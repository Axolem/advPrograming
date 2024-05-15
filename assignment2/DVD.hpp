#pragma once
#ifndef DVD_hpp
#define DVD_hpp

#include <string>

class DVD
{
private:
	std::string name;
	std::string director;
	std::string category;
	float price;

	// These are mine not required by the question
	std::string strupper(std::string);
	std::string strtrim(std::string);

public:
	DVD();
	DVD(std::string, std::string, std::string, float);
	void setName(std::string);
	void setDirector(std::string);
	void setCategory(std::string);
	void setPrice();
	std::string getName();
	std::string getDirector();
	std::string getCategory();
	float getPrice() const;

};
#endif // !DVD_hpp



