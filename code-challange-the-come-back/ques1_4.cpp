#include "ques1_4.hpp"

float TwelveMonthAccount::interestRate = 0.0;

void TwelveMonthAccount::setInterestRate(float interest) {
	interestRate = interest;
}

TwelveMonthAccount::TwelveMonthAccount(int aN, std::string fN, std::string sN, char aC, int rC,int b)
	: Account(aN, fN, sN, aC, rC) {
	balance = b;
}

TwelveMonthAccount::TwelveMonthAccount() {
	balance = 0.0;
}.0.00000000000000000000000000000000000


float TwelveMonthAccount::calculateInterest() const {
	return balance * interestRate / 100;
}

float TwelveMonthAccount::determineAmountPayable() const {
	float total = (balance + calculateInterest()) / 12;

	if (total < 200) {
		return 200;
	}

	return total;
}
