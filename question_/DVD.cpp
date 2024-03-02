#include"DVD.hpp"

DVD::DVD() {
	cName = "";
	cDirector = "";
	cCategory = "";
	cPrice = 0;
}

DVD::DVD(string cName, string cDirector, string cCategory, float cPrice) {
	this->cName = cName;
	this->cDirector = cDirector;
	this->cCategory = cCategory;
	this->cPrice = cPrice;
}

void DVD::setName(string name) {
	cName = name;
}

void DVD::setCategory(string category) {
	cCategory = category;
}

void DVD::setDirector(string director) {
	cDirector = director;
}

void DVD::setPrice(float price) {
	cPrice = price;
}

string DVD::getName() {
	return cName;
}

string DVD::getDirector() {
	return cDirector;
}

string DVD::getCategory() {
	return cCategory;
}

float DVD::getPrice() {
	return cPrice;
}

