#include "Crop.hpp"

Crop::Crop() : cropName(""), numberOfUnits(0), pricePerUnit(0), cropExpences(0) {}

Crop::Crop(std::string cropName, float numberOfUnits, float pricePerUnit, float cropExpences)
    : cropName(cropName), numberOfUnits(numberOfUnits), pricePerUnit(pricePerUnit), cropExpences(cropExpences) {}


std::string Crop::getCropName() const {
    return cropName;
}

float Crop::getNumberOfUnits() const {
    return numberOfUnits;
}

float Crop::getPricePerUnit() const {
    return pricePerUnit;
}

float Crop::getCropExpences() const {
    return cropExpences;
}


void Crop::setCropName(std::string cropName) {
    this->cropName = cropName;
}

void Crop::setNumberOfUnits(float numberOfUnits) {
    this->numberOfUnits = numberOfUnits;
}

void Crop::setPricePerUnit(float pricePerUnit) {
    this->pricePerUnit = pricePerUnit;
}

void Crop::setCropExpences(float cropExpences) {
    this->cropExpences = cropExpences;
}
