#pragma once
#ifndef SecondYearStudent_hpp

#include"Student.hpp"

class SecondYearStudent :Student
{
private:
	string code[4];

	double assignment[4];
	double test[4];
	double predicate[4];
	double exam[4];
	double final[4];

	int testWeight;
	int assignmentWeight;

	void calcPredicate();
	double determineStudentAvg() const;

public:
	SecondYearStudent();

	void calcFinalMark();
	void displayStudent();
	/*
* studentNo, name, surname, code, test, assignment
*/
	void setStudent(int, char[], char[], string[], double[], double[]);
};

#endif 



