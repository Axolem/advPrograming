#include "Farmer.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

Farmer::Farmer(std::string fileName) : fileName(fileName), farmCounter(0) {
	std::ifstream file(fileName);
	std::string line;
	Farm* currentFarm = nullptr;

	while (std::getline(file, line)) {
		if (line[0] == '#') {
			if (currentFarm != nullptr) {
				farms[farmCounter++] = currentFarm;
			}
			currentFarm = new Farm(line.substr(1));
		}
		else if (currentFarm != nullptr) {
			AdvancedCrop crop = extractCropFromLine(line);
			currentFarm->addCrop(crop);
		}
	}

	if (currentFarm != nullptr) {
		farms[farmCounter++] = currentFarm;
	}
}

Farmer::~Farmer() {
	for (int i = 0; i < farmCounter; ++i) {
		delete farms[i];
	}
}

AdvancedCrop Farmer::extractCropFromLine(std::string line) {
	std::stringstream ss(line);
	std::string cropName, numberOfUnits, pricePerUnit, cropExpences, sizeOfCrop, propertyTax;
	std::getline(ss, cropName, ',');
	std::getline(ss, numberOfUnits, ',');
	std::getline(ss, pricePerUnit, ',');
	std::getline(ss, cropExpences, ',');
	std::getline(ss, sizeOfCrop, ',');
	std::getline(ss, propertyTax, ',');

	return AdvancedCrop(cropName, std::stof(numberOfUnits), std::stof(pricePerUnit), std::stof(cropExpences), std::stof(sizeOfCrop), std::stof(propertyTax));
}

int Farmer::getNumberOfFarms() const {
	return farmCounter;
}

Farm& Farmer::getFarmAt(int index) {
	return *farms[index];
}

float Farmer::getTotalProfit() const {
	float totalProfit = 0.0;
	for (int i = 0; i < farmCounter; ++i) {
		totalProfit += farms[i]->getProfit();
	}
	return totalProfit;
}

int Farmer::getProfitLessFarms(std::string farmNames[], float losses[]) const {
	int lossCounter = 0;
	for (int i = 0; i < farmCounter; ++i) {
		float profit = farms[i]->getProfit();
		if (profit < 0) {
			farmNames[lossCounter] = farms[i]->getName();
			losses[lossCounter] = profit;
			++lossCounter;
		}
	}
	return lossCounter;
}
