#pragma once
#ifndef Student_hpp

#include<iostream>

using namespace std;

class Student
{
protected:
	int studentNumber;
	char name[29];
	char surname[29];

public:
	Student();
	void setStudent(int, char[], char[]);
	void displayStudent();
};

#endif 




