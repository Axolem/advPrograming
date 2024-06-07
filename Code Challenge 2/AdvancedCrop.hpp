#ifndef ADVANCEDCROP_HPP
#define ADVANCEDCROP_HPP

#include "Crop.hpp"

class AdvancedCrop : public Crop {
protected:
	float sizeOfCrop;
	float propertyTax;

public:
	AdvancedCrop(std::string cropName, float numberOfUnits, float pricePerUnit, float cropExpences, float sizeOfCrop, float propertyTax);
	AdvancedCrop(const AdvancedCrop& other);

	float getProduceProfit() const;

	float getSizeOfCrop() const;
	float getPropertyTax() const;

	void setSizeOfCrop(float sizeOfCrop);
	void setPropertyTax(float propertyTax);
};

#endif // ADVANCEDCROP_HPP
