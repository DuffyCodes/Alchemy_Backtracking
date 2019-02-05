
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

#include "reaction.h"

using namespace std;



void alchemy (istream& in)
{
  map<string,int> quantities;
  vector<Reaction> reactions;
  string chem1, chem2;
  int temp;
  int amount;
  in >> chem1;
  while (chem1 != "0") {
    in >> chem2 >> temp;
    Reaction r {chem1, chem2, temp};
    reactions.push_back (r);
    quantities[chem1] = 0;
    quantities[chem2] = 0;
    in >> chem1;
  }
  getline (in, chem1);
  in >> chem1;
  while (chem1 != "0") {
    in >> amount;
    quantities[chem1] = amount;
    in >> chem1;
  }
  getline (in, chem1);

  int maxTemp = findMaxTemp(quantities, reactions);

  cout << "The temperature in the jar will change by at most "
       << maxTemp << " degrees." << endl;
}







int main(int argc, char** argv)
{
	if (argc > 1)
	{
		ifstream in(argv[1]);
		alchemy(in);
	}
	else
		alchemy(cin);
  return 0;
}
