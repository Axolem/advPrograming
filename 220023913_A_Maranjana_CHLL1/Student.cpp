#include "Student.hpp"
#include <cstring>


Student::Student()
{
	strcpy_s(name, "");
	strcpy_s(surname, "");
	studentNumber = 0;
}

void Student::setStudent(int studentNo, char name[], char surname[]) {
	strcpy_s(this->name, name);
	strcpy_s(this->surname, surname);
	studentNumber = studentNo;
}

void Student::displayStudent() {
	cout <<
		studentNumber
		<< "\t" << name
		<< "\t" << surname
		<< endl;
}

