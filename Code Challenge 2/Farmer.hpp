#ifndef FARMER_HPP
#define FARMER_HPP

#include "Farm.hpp"
#include <string>
#include <vector>

class Farmer {
private:
	std::string fileName;
	Farm* farms[30];
	int farmCounter;

	AdvancedCrop extractCropFromLine(std::string line);

public:
	Farmer(std::string fileName);

	~Farmer();

	int getNumberOfFarms() const;
	Farm& getFarmAt(int index);

	float getTotalProfit() const;

	int getProfitLessFarms(std::string farmNames[], float losses[]) const;
};

#endif // FARMER_HPP
