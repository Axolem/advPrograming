#include "DVD.hpp"

DVD::DVD()
{
	name = "";
	director = "";
	category = "";
	price = 0.0;
}

DVD::DVD(std::string name, std::string director, std::string category, float price)
{
	this->name = strtrim(name);
	this->director = strtrim(director);
	this->category = strupper(strtrim(category));
	this->price = price;
}

void DVD::setName(std::string name)
{
	this->name = strtrim(name);
}

void DVD::setDirector(std::string director)
{
	this->director = strtrim(director);
}

void DVD::setCategory(std::string category)
{
	this->category = strupper(strtrim(category));
}

void DVD::setPrice()
{
	if (this->category == strupper("comedy"))
		this->price = 40.00;
	else if (this->category == strupper("drama"))
		this->price = 30.00;
	else if (this->category == strupper("action"))
		this->price = 45.00;
	else
		this->price = 25.00;
}

std::string DVD::getName()
{
	return name;
}

std::string DVD::getDirector()
{
	return director;
}

std::string DVD::getCategory()
{
	return category;
}

float DVD::getPrice() const
{
	return price;
}

std::string DVD::strupper(std::string str)
{
	std::string lowerStr = "";
	for (int i = 0; i < str.length(); i++)
	{
		lowerStr += toupper(str[i]);
	}
	return lowerStr;
}

std::string DVD::strtrim(std::string str)
{
	while (str[0] == ' ')
	{
		str = str.substr(1, str.length() - 1);
	}

	while (str[str.length() - 1] == ' ')
	{
		str = str.substr(0, str.length() - 1);
	}

	return str;
}
