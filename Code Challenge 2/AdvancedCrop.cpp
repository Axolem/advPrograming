#include "AdvancedCrop.hpp"

AdvancedCrop::AdvancedCrop(std::string cropName, float numberOfUnits, float pricePerUnit, float cropExpences, float sizeOfCrop, float propertyTax)
	: Crop(cropName, numberOfUnits, pricePerUnit, cropExpences), sizeOfCrop(sizeOfCrop), propertyTax(propertyTax) {}

AdvancedCrop::AdvancedCrop(const AdvancedCrop& other)
	: Crop(other.cropName, other.numberOfUnits, other.pricePerUnit, other.cropExpences), sizeOfCrop(other.sizeOfCrop), propertyTax(other.propertyTax) {}


float AdvancedCrop::getProduceProfit() const {
	float totalRevenue = numberOfUnits * pricePerUnit;
	float totalExpenses = cropExpences + (sizeOfCrop * propertyTax);
	return totalRevenue - totalExpenses;
}


float AdvancedCrop::getSizeOfCrop() const {
	return sizeOfCrop;
}

float AdvancedCrop::getPropertyTax() const {
	return propertyTax;
}

void AdvancedCrop::setSizeOfCrop(float sizeOfCrop) {
	this->sizeOfCrop = sizeOfCrop;
}

void AdvancedCrop::setPropertyTax(float propertyTax) {
	this->propertyTax = propertyTax;
}
