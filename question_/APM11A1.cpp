#include <fstream> 
#include<iostream>
#include<string>
#include <sstream>

using namespace std;

int main() {
	string filePath = "Source.csv";
	string line;

	ifstream ourFile; // Open file for reading

	ourFile.open(filePath, ios::in);

	while (!ourFile.eof()) {
		if (ourFile.is_open()) {
			getline(ourFile, line); // Read a line from the file
			stringstream ss(line);
			string name;
			getline(ss, name, ',');
			cout << name << endl;   // Print the line to the console

		}
		else {
			cout << "Unable to open file" << endl;
		}
	}
	ourFile.close();        // Close the file

	system("pause");
	return 0;
}