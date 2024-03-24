#include"ques1_2.cpp"
#ifndef TwelveMonthsAccount_
class TwelveMonthAccount : public Account {
	static float interestRate;
	float calculateInterest() const;

public:
	TwelveMonthAccount(int, std::string, std::string, char, int, float, std::string[4][2], int[4][3]);
	static void setInterestRate(float);
	float determineAmountPayable();
};

TwelveMonthAccount::TwelveMonthAccount(int account_no, std::string f_name, std::string l_name, char account_category, int repayment_category, float balance_, std::string account_category_arr[4][2], int credit_limit[4][3])
	: Account(account_no, f_name, l_name, account_category, repayment_category, balance_, account_category_arr, credit_limit) {

}

void TwelveMonthAccount::setInterestRate(float interest) {
	interestRate = interest;
}


float TwelveMonthAccount::calculateInterest() const {
	return balance * interestRate / 100;
}

float TwelveMonthAccount::determineAmountPayable() {
	float total = (balance + calculateInterest()) / 12;

	if (total < 200) {
		return 200;
	}

	return total;
}
#endif // !TwelveMonthsAccount_
