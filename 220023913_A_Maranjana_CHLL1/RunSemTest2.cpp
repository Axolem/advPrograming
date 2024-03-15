#include<fstream>
#include<iostream>
#include<sstream>
#include<stdlib.h>

#include"SecondYearStudent.hpp"




static void loadStudentInfo(string filename, SecondYearStudent students[])
{
const int TOTAL_STUDENTS = 4;

	ifstream myfile;

	myfile.open(filename, ios::in);
	if (!myfile.is_open())
	{
		cout << "File not opened" << endl;
		exit(2);
	}

	string line;
	int counter = 0;
	string subCodes[TOTAL_STUDENTS] = { "DSO", "TPG", "ISY", "SSF" };

	while (!myfile.eof() && myfile.is_open()) {
		getline(myfile, line);

		stringstream linestream(line);

		int studentNumber = 0;
		string name, surname, str_studentNo;
		double assignmentMarks[TOTAL_STUDENTS] = {}, testMarks[TOTAL_STUDENTS] = {};

		getline(linestream, str_studentNo, ',');
		getline(linestream, name, ',');
		getline(linestream, surname, ',');

		studentNumber = std::stoi(str_studentNo);

		for (int i = 0; i < TOTAL_STUDENTS; i++) {
			getline(linestream, line, ',');
			assignmentMarks[i] = std::stod(line);
			getline(linestream, line, ',');
			testMarks[i] = std::stod(line);
		}

		char name_[29];
		char surname_[29];

		strncpy_s(name_, name.c_str(), sizeof(name_));
		strncpy_s(surname_, surname.c_str(), sizeof(surname_));


		name_[sizeof(name_) - 1] = '\0';
		surname_[sizeof(surname_) - 1] = '\0';

		//std::cout << *testMarks << endl;
		students[counter].setStudent(studentNumber, name_, surname_, subCodes, assignmentMarks, testMarks);
		counter++;
	}
}
int main() {
	const int TOTAL_STUDENTS = 4;

	SecondYearStudent students[TOTAL_STUDENTS] = {};

	loadStudentInfo("Students.csv", students);

	SecondYearStudent* students_ptr = students;

	int counter = 0;
	while (counter < TOTAL_STUDENTS) {
		students_ptr->calcFinalMark();
		students_ptr->displayStudent();

		students_ptr++;
		counter++;
	}

	//delete students_ptr;

	system("pause");
	return 0;
}