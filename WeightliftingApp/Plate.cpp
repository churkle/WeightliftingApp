#include "Plate.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

//Create new Plate with default weight of 0.0 pounds and quantity of 0
Plate::Plate() : weight{ 0.0 }, quantity{ 0 }, quantityNeeded{ 0 }
{
}

//Create new Plate with weight given by argument, and default quantity of 0
Plate::Plate(double givenWeight) : weight{ givenWeight }, quantity{ 0 }, quantityNeeded{ 0 }
{
}

//Create new Plate with weight given by argument, and default quantity of 0
Plate::Plate(double givenWeight, int givenQuantity) : weight{ givenWeight }, quantity{ givenQuantity }, quantityNeeded{ 0 }
{
}

Plate::~Plate()
{
}

//Returns the plate's weight
double Plate::getWeight()
{
	return weight;
}

//Returns the quantity of the plate
int Plate::getQuantity()
{
	return quantity;
}

//Returns quantity of plate needed to attain total weight
int Plate::getQuantityNeeded()
{
	return quantityNeeded;
}

//Returns true if first plate has a larger weight than the second plate
bool Plate::compareWeight(const Plate &p1, const Plate &p2)
{
	return p1.weight > p2.weight;
}

//Returns true if first plate has a larger quantity than the second plate
bool Plate::compareQuantity(const Plate &p1, const Plate &p2)
{
	return p1.quantity > p2.quantity;
}

//Outputs quantity of each plate weight necessary to create total weight
void Plate::countWeight(vector<Plate> plates, double totalWeight)
{
	totalWeight -= 45.0;

	if (totalWeight < 0)
	{
		cout << "Weight is not high enough." << endl;
		return;
	}

	sortPlates(plates);

	for (auto &plate : plates)
	{
		plate.setQuantityNeeded(totalWeight);
		totalWeight -= (plate.getQuantityNeeded() * 2.0 * plate.getWeight());

		if (totalWeight == 0.0)
		{
			break;
		}
	}

	if (totalWeight != 0.0)
	{
		cout << "Unable to create weight with current collection of plates." << endl;
		return;
	}

	for (auto plate : plates)
	{
		cout << plate.getWeight() << " : " << plate.getQuantityNeeded() << endl;
	}
}

//Sorts vector of Plates by descending weight
void Plate::sortPlates(std::vector<Plate> plates)
{
	sort(plates.begin(), plates.end(), compareWeight);
}

//Sets the necessary quantity for the plate to reach the total weight
void Plate::setQuantityNeeded(double totalWeight)
{
	quantityNeeded = totalWeight / (weight * 2.0);

	if (quantityNeeded * 2 > quantity)
	{
		quantityNeeded = quantity / 2;
	}
}
