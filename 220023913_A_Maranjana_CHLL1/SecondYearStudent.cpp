#include "SecondYearStudent.hpp"
#include <cstdlib>

const int TOTAL_STUDENTS = 4;

SecondYearStudent::SecondYearStudent() {
	testWeight = 60;
	assignmentWeight = 40;

	for (int i = 0; i < TOTAL_STUDENTS; i++)
	{
		code[i] = "";
		assignment[i] = 0.0;
		test[i] = 0.0;
		exam[i] = 0.0;
		this->final[i] = 0.0;
		predicate[i] = 0.0;
	}
}


void SecondYearStudent::setStudent(int studentNo, char name[], char surname[], string code[], double assignment[], double test[])
{
	studentNumber = studentNo;
	strcpy_s(this->name, name);
	strcpy_s(this->surname, surname);

	for (int i = 0; i < TOTAL_STUDENTS; i++)
	{
		this->code[i] = code[i];
		this->test[i] = test[i];
		this->assignment[i] = assignment[i];
	}
}

void SecondYearStudent::calcPredicate() {
	// (assignment * assignmentWeight) + (test * testWeight) / 100
	for (int i = 0; i < TOTAL_STUDENTS; i++)
	{
		predicate[i] = ((test[i] * testWeight) + (assignment[i] * assignmentWeight)) / 100.0;
	}
}

void SecondYearStudent::calcFinalMark() {

	SecondYearStudent::calcPredicate();

	for (int i = 0; i < TOTAL_STUDENTS; i++)
	{
		exam[i] = rand() % 100 + 1;

		this->final[i] = (predicate[i] + exam[i]) / 2.0;
	}
}

double SecondYearStudent::determineStudentAvg() const {
	double total = 0;

	for (int i = 0; i < TOTAL_STUDENTS; i++)
	{
		total += this->final[i];
	}

	return total / TOTAL_STUDENTS;
}

void SecondYearStudent::displayStudent() {
	/*student
		number, student name, the subject code
		for each of the four subjects, the
			predicate, exam mark and the final
			mark, as well as the average mark*/
	Student::displayStudent();

	for (int i = 0; i < TOTAL_STUDENTS; i++)
	{
		cout <<
			"\t" <<
			code[i]
			<< "\t" << predicate[i]
			<< "\t" << exam[i]
			<< "\t" << this->final[i]
			<< "%"
			<< endl;
	}
	cout <<
		"\t" <<
		"Average: "
		<< SecondYearStudent::determineStudentAvg()
		<< endl;


}