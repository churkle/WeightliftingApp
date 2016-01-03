#pragma once
#include <vector>

class Plate
{
public:
	Plate();
	Plate(double givenWeight);
	Plate(double givenWeight, int givenQuantity);
	~Plate();

	double getWeight();
	int getQuantity();
	int getQuantityNeeded();
	static bool compareWeight(const Plate &p1, const Plate &p2);
	static bool compareQuantity(const Plate &p1, const Plate &p2);
	static void countWeight(std::vector<Plate> plates, double totalWeight);
	static void sortPlates(std::vector<Plate> plates);

private:
	double weight;
	int quantity;
	int quantityNeeded;

	void setQuantityNeeded(double totalWeight);
};

