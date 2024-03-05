#pragma once
#ifndef StockList_hpp
#define StockList_hpp

#include"DVD.hpp"
#include<string>

using namespace std;

class StockList
{
private:
	string cCategoryList[30];
	int cCategoryCounter;
	DVD cDVDList[30];
	int cDVDCounter;
	DVD extractDVDFromString(string);

public:
	StockList();

	void addDVD(DVD&);
	bool addCategory(string);
	void loadDVDsFromFile(string);
	float determineAverageDVDPrice(string category);
	string* getListOfCategories();
};

#endif // !1


