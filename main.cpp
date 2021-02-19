#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"
#include "reverseorder.h"

using namespace std;

int main()
{
  cout << "05/20/2018" << endl;
  cout << get_east_storage("05/20/2018") << " billion gallons" << endl;
  cout << "Min Val:" << endl;
  cout << get_min_east() << " billion gallons" << endl;
  cout << "Max Val:" << endl;
  cout << get_max_east() << " billion gallons" << endl;
  cout << "09/13/2018:" << endl;
  cout << compare_basins("09/13/2018") << " is higher" << endl;
  cout << "07/27/2018:" << endl;
  cout << compare_basins("07/27/2018") << " is higher" << endl;
  cout << "West Levels between 05/29/2018 and 06/02/2018 in feet are:"<< endl;
  reverse_oreder("05/29/2018","06/02/2018");
  return 0;
}
