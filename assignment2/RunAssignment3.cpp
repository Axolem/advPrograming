#include"DVD.hpp"
#include<fstream>
#include<iostream>
#include<sstream>
#include<stack>

static void readFromFile(std::string fileName, std::stack<DVD>& dvdStack) {
	std::ifstream file;

	file.open(fileName);

	if (!file.is_open()) {
		std::cout << "File " << fileName << " could not be opened" << std::endl;
		exit(1);
	}

	std::string line;
	while (!file.eof())
	{
		std::getline(file, line);
		std::string name, category, director;
		float price = 0;

		// The question paper said we split by comma but the file is separated by space
		char separator = ' ';

		std::stringstream line_stream(line);
		std::getline(line_stream, name, separator);
		std::getline(line_stream, director, separator);
		std::getline(line_stream, category, separator);
		// Lecture's file came with the prices
		line_stream >> price;

		DVD dvd(name, director, category, price);
		dvd.setPrice();
		dvdStack.push(dvd);
	}
	file.close();
}

int main() {
	std::stack<DVD> dvdStack;
	std::string fileName = "DVD.txt";

	readFromFile(fileName, dvdStack);

	while (!dvdStack.empty()) {
		DVD dvd = dvdStack.top();
		dvdStack.pop();
		std::cout
			<< dvd.getName() << " "
			<< dvd.getDirector() << " "
			<< dvd.getCategory() << " "
			<< dvd.getPrice()
			<< std::endl;
	}
	return 0;
}