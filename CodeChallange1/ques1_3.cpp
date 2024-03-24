#include"ques1_2.cpp"
#ifndef SixMonthAccount
class SixMonthAccount : public Account {
private:
	static float clubFee;

public:
	//SixMonthAccount();
	SixMonthAccount(int a = 0, std::string b = "", std::string c = "", char d = 'P', int e = 0, float f = 0.00, std::string[4][2], int[4][3]);
	static void setClubFee(float);
	float determineAmountPayable();
};

#endif SixMonthAccount

SixMonthAccount::SixMonthAccount(int account_no, std::string f_name, std::string l_name, char account_category, int repayment_category, float balance_, std::string account_category_arr[4][2], int credit_limit[4][3])
	: Account(account_no, f_name, l_name, account_category, repayment_category, balance_, account_category_arr, credit_limit) {

}

//SixMonthAccount::SixMonthAccount() {
//
//}

void SixMonthAccount::setClubFee(float fee) {
	clubFee = fee;
}

float SixMonthAccount::determineAmountPayable() {
	float amount = balance / 6;

	if (amount < 100) {
		return 100  + clubFee;
	}
	else {
		return amount + clubFee;
	}
}	

