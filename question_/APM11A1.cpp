#include <fstream> 
#include<iostream>
#include <sstream>
#include<string>

#include"DVD.hpp"
#include"StockList.hpp"

using namespace std;

int main() {
	string filePath = "Source.csv";

	// 1. Create the object
	DVD dvd_1 = DVD();
	StockList my_stock_list = StockList();

	// 2. Read the file
	my_stock_list.loadDVDsFromFile(filePath);

	// 3. We display the avarage for each DVD category
	string* categories;

	categories = my_stock_list.getListOfCategories();


	for (int i = 0; i < sizeof(categories); i++)
	{
		float x = my_stock_list.determineAverageDVDPrice(categories[i]);
		cout << x << endl;
	}

	system("pause");
	return 0;
}