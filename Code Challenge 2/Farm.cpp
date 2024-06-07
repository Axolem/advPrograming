#include "Farm.hpp"

Farm::Farm(std::string farmName) : farmName(farmName), cropCounter(0) {}

Farm::~Farm() {
	for (int i = 0; i < cropCounter; ++i) {
		delete crops[i];
	}
}


std::string Farm::getName() const {
	return farmName;
}

void Farm::addCrop(AdvancedCrop& advCrop) {
	if (cropCounter < 10) {
		crops[cropCounter++] = new AdvancedCrop(advCrop);
	}
}


float Farm::getProfit() const {
	float totalProfit = 0.0;
	for (int i = 0; i < cropCounter; ++i) {
		totalProfit += crops[i]->getProduceProfit();
	}
	return totalProfit;
}
