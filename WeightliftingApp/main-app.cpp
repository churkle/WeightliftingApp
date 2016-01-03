// File name: main-app.cpp
// Author: Charles Fei
// Project: Weightlifting Plate counter
// Date: 5/5/2014
// Description: Program that takes a weight in pounds and outputs the required quantity of each plate weight


#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "Plate.h"

using namespace std;

int main()
{
	vector<Plate> plates;
	double weight, totalWeight;
	int quantity;
	string line;

	cout << "Enter Plates" << endl;

	getline(cin, line);
	istringstream iss(line);
	while (iss >> weight >> quantity)
	{
		plates.push_back(Plate(weight, quantity));
	}

	Plate::sortPlates(plates);
	for (auto plate : plates)
	{
		cout << plate.getWeight() << " : " << plate.getQuantity() << endl;;
	}

	cout << "Enter total weight" << endl;
	cin >> totalWeight;

	Plate::countWeight(plates, totalWeight);

	system("pause");
}