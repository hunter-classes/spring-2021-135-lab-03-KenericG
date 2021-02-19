#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reverseorder.h"

using namespace std;

void reverse_oreder(std::string date1, std::string date2){
    string buf;
    double eastSt,westEl;
    double rev[365];
    int x = 0;
    bool flag = false;

    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    getline(fin,buf);

    while(fin >> buf >> eastSt >> eastSt >> eastSt >> westEl && buf != date2) {
        fin.ignore(INT_MAX, '\n');
        if (buf == date1){
            flag = true;
        }
        if (flag == true){
            rev[x] = westEl;
            x++;    
        }
    }
    rev[x] = westEl;

    for (int i = x; i >= 0; i--){
        cout << rev[i] << endl;
    }
    fin.close();
}