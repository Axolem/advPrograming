#include "Farmer.hpp"
#include <iostream>

int main() {
	Farmer farmer("Farm.txt");

	// a list of all the farm names as well as their profit
	std::cout << "Farm Name \t\t      | Profit:" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	for (int i = 0; i < farmer.getNumberOfFarms(); ++i) {
		Farm& farm = farmer.getFarmAt(i);
		std::cout << farm.getName().append(30 - farm.getName().length(), ' ') << "| R " << farm.getProfit() << "0" << std::endl;
	}

	//  total profit of the farmer
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "Total Profit: R " << farmer.getTotalProfit() << "0" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;


	// arms that are running at a loss
	std::string farmNames[30];
	float losses[30];
	int lossCount = farmer.getProfitLessFarms(farmNames, losses);

	std::cout << "" << std::endl;
	std::cout << "Lossing farms:" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	for (int i = 0; i < lossCount; ++i) {
		std::cout << farmNames[i].append(30 - farmNames[i].length(), ' ') << "| R " << losses[i] << "0" << std::endl;
	}
	std::cout << "-------------------------------------------" << std::endl;

	return 0;
}
