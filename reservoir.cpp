#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"

using namespace std;

string buf;
double eastSt,eastEl,westSt,westEl;

double get_east_storage(string date){
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    getline(fin,buf);

    while(fin >> buf >> eastSt && buf != date) {
        fin.ignore(INT_MAX, '\n');
    }
    fin.close();
    return eastSt;
}

double get_min_east(){
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    getline(fin,buf);

    fin >> buf >> eastSt;
    fin.ignore(INT_MAX, '\n');
    eastEl = eastSt;

    while(fin >> buf >> eastSt) {
        fin.ignore(INT_MAX, '\n');
        if (eastSt < eastEl){
            eastEl = eastSt;
        }
    }
    return eastEl;
}

double get_max_east(){
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    getline(fin,buf);

    fin >> buf >> eastSt;
    fin.ignore(INT_MAX, '\n');
    eastEl = eastSt;

    while(fin >> buf >> eastSt) {
        fin.ignore(INT_MAX, '\n');
        if (eastSt > eastEl){
            eastEl = eastSt;
        }
    }
    return eastEl;
}

std::string compare_basins(std::string date){
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    getline(fin,buf);

    while(fin >> buf >> eastSt >> eastEl >> westSt >> westEl && buf != date) {
        fin.ignore(INT_MAX, '\n');
    }
    fin.close();

    if (eastEl > westEl){
        return "East";
    }
    if (westEl > eastEl){
        return "West";
    }
    if (eastEl == westEl){
        return "Equal";
    }
    return "Error";    
}