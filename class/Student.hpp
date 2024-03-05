#pragma once
#include <stirng>

class Student
{
public:
	Student();
	

private:
	int age;
	int studentNumber;
	string name;

};

Student::Student()
{
}

Student::Student(string, int, int)