// File name: main-app.cpp
// Author: Charles Fei
// Project: Weightlifting Plate counter
// Date: 5/5/2014
// Description: Program that takes a weight in pounds and outputs the required quantity of each plate weight


#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct plate
{
	double weight;
	int quantity;
};

void countPlates(vector<plate>& plates, double givenWeight)
{

}

void quickSort(vector<plate>& plates, int start, int end)
{
	while (end - start > 0)
	{
		double pivot = plates[end].weight;
		int firstLarger = start;

		for (size_t i = start; i < end; i++)
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

	while (cin >> num)
	{
		plate *tmp = new plate;
		tmp->weight = num;
		plates.push_back(*tmp);
	}

	quickSort(plates, 0, plates.size());

	for (size_t i = 0; i < plates.size(); i++)
	{
		cout << plates[i].weight << " ";
	}

	cout << "Please enter the weight you want to use: ";
	cin >> weight;

	countPlates(plates, weight);
}