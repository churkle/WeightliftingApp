// File name: main-app.cpp
// Author: Charles Fei
// Project: Weightlifting Plate counter
// Date: 5/5/2014
// Description: Program that takes a weight in pounds and outputs the required quantity of each plate weight


#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct plate
{
	double weight;
	int quantity = 0;
};

void countPlates(vector<plate>& plates, double givenWeight)
{
	double weight = givenWeight - 45.0;

	if (weight >= 0)
	{
		for (size_t i = plates.size() - 1; i >= 0; i--)
		{
			if (fmod(weight, plates[i].weight * 2.0) == 0)
			{
				plates[i].quantity = (int) (weight / (plates[i].weight * 2.0));
				weight = 0.0;
				break;
			}
			else
			{
				plates[i].quantity = weight / (plates[i].weight * 2.0);
				weight = fmod(weight, (plates[i].weight * 2.0));
			}
		}

		if (weight == 0.0)
		{
			for (int j = plates.size() - 1; j >= 0; j--)
			{
				if (plates[j].quantity != 0)
				{
					cout << plates[j].weight << ": " << plates[j].quantity << endl;
				}
			}
		}
		else
		{
			cout << "Weight impossible to create with current combination of weights." << endl;
		}
	}
	else
	{
		cout << "Weight is less than a bar." << endl;
	}
}

void quickSort(vector<plate>& plates, int start, int end)
{
	if(end - start > 0)
	{
		double pivot = plates[end].weight;
		int firstLarger = start;

		for (int i = start; i < end; i++)
		{
			if (plates[i].weight <= pivot)
			{
				std::swap(plates[i], plates[firstLarger]);
				firstLarger++;
			}
		}

		std::swap(plates[end], plates[firstLarger]);
		quickSort(plates, start, firstLarger - 1);
		quickSort(plates, firstLarger + 1, end);
	}
}

int main()
{
	vector<plate> plates;
	double num, weight;

	cout << "Please enter the plate weights you have: ";

	while (cin >> num && num != 0)
	{
		plate *tmp = new plate;
		tmp->weight = num;
		plates.push_back(*tmp);
	}

	quickSort(plates, 0, plates.size() - 1);

	cout << "Please enter the weight you want to use: ";
	cin >> weight;

	countPlates(plates, weight);
	system("pause");
}