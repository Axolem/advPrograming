#pragma once
#ifndef CROP_HPP

#include <string>

class Crop {
protected:
	std::string cropName;
	float numberOfUnits;
	float pricePerUnit;
	float cropExpences;

public:
	Crop();
	Crop(std::string cropName, float numberOfUnits, float pricePerUnit, float cropExpences);

	std::string getCropName() const;
	float getNumberOfUnits() const;
	float getPricePerUnit() const;
	float getCropExpences() const;

	void setCropName(std::string cropName);
	void setNumberOfUnits(float numberOfUnits);
	void setPricePerUnit(float pricePerUnit);
	void setCropExpences(float cropExpences);
};

#endif // CROP_HPP

