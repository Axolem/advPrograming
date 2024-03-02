#pragma once
#ifndef DVD_hpp
#define DVD_hpp

#include<string>

using namespace std;

class DVD {
private:
	std::string cName;
	string cDirector;
	string cCategory;
	float cPrice;

public:
	DVD();
	DVD(string, string, string, float);
	void setName(string);
	void setDirector(string);
	void setCategory(string);
	void setPrice(float);
	string getName();
	string getDirector();
	string getCategory();
	float getPrice();
};

#endif // !DVD_hpp
