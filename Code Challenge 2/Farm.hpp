#ifndef FARM_HPP
#define FARM_HPP

#include "AdvancedCrop.hpp"
#include <string>

class Farm {
private:
	AdvancedCrop* crops[10];
	int cropCounter;
	std::string farmName;

public:
	Farm(std::string farmName);

	~Farm();

	std::string getName() const;

	void addCrop(AdvancedCrop& advCrop);

	float getProfit() const;
};

#endif // FARM_HPP
