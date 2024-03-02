#include "StockList.hpp"
#include <fstream> 
#include<iostream>
#include <sstream>

using namespace std;

StockList::StockList() {
	cCategoryCounter = 0;
	cDVDCounter = 0;
	cCategoryList[29] = {};
	cDVDList[29] = {};
}

// DVDName,DirectorSurname,Category,Price
// Coding,maranjana,educational,450
DVD StockList::extractDVDFromString(string line) {
	// 0. Create an empty DVD object
	DVD theDvd = DVD();

	// 1. Split by ','
	stringstream ss(line);
	string name, director, category, price;


	// 2. loop and search based on the input
	getline(ss, name, ',');
	getline(ss, director, ',');
	getline(ss, category, ',');
	ss >> price;

	// Add cvalues to our object
	theDvd.setName(name);
	theDvd.setDirector(director);
	theDvd.setCategory(category);
	theDvd.setPrice(stof(price));

	// DVD oneLine = DVD(name, director, category, stof(price));

	// 3. Return the DVD
	return theDvd;
}

void StockList::addDVD(DVD& dvd) {
	// Add the dvd
	cDVDList[cDVDCounter] = dvd;

	// Increament how many dvds we have
	cDVDCounter++;
}

bool StockList::addCategory(string category) {
	bool added = false;
	// 1. Check if the category exist
	for (int i = 0; i < cCategoryCounter; i++) {
		if (cCategoryList[i] == category) {
			added = true;
		}

		// added = (cCategoryList[i] == category);
	}

	// 2. Add it if not
	if (added != true) {
		cCategoryList[cCategoryCounter] = category;
		added = true;
		cCategoryCounter++;
	}

	// 3. return
	return added;
}

void StockList::loadDVDsFromFile(string fileName) {
	string line;

	ifstream ourFile;

	// Open file for reading
	ourFile.open(fileName, ios::in);

	while (!ourFile.eof() && ourFile.is_open()) {
		getline(ourFile, line); // Read a line from the file
		DVD  newDvd = extractDVDFromString(line);
		cDVDList[cDVDCounter] = newDvd;
		cDVDCounter++;
	}

	ourFile.close();        // Close the file
}

