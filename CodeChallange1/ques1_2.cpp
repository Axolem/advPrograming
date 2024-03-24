#include"ques1_1.cpp"
#include<fstream>
#include <iostream>
#include<map>
#include<sstream>
#include<string>
#ifndef Account


class Account
{
protected:
	int accountNumber;
	std::string firstName;
	std::string lastName;
	char accountCategory;
	int repaymentCategory;
	float balance;

	static std::string accountCategoryArr[4][2];
	static int creditLimit[4][3];


public:
	//Account();
	/*
	* account_number, f_name, l_name, accountCategory, repaymentCategory, balance, accountCategoryArr, creditLimit
	*/
	Account(int a = 0, std::string b = "", std::string c = "", char d = 'P', int e = 0, float f = 0.00, std::string[4][2], int[4][3]);

	/*
	* account_number, f_name, l_name, accountCategory, repaymentCategory, balance, accountCategoryArr
	*/
	void setAccount(int, std::string, std::string, char, int, float);

	/*
	* filename
	*/
	static void readAndSetCreditLimits(std::string);

	int determineCreditLimit();

	Account& operator+(Transaction&);

	float determineAmountPayable();

	float getBalance();

	std::map<std::string, std::string> getAccount();
};
#endif

//Account::Account() {
//	accountNumber = 0;
//	firstName = "";
//	lastName = "";
//	accountCategory = 'P';
//	repaymentCategory = 1;
//	balance = 0;
//
//	int creditLimit[4][3] = {
//			{300,  600,  900},
//			{500,  1000, 1500},
//			{1000, 2000, 3000},
//			{5000, 7000, 10000}
//	};
//
//	std::string accountCategoryArr[4][2] = {
//		{ "P","Platinum" },
//		{ "G","Gold" },
//		{ "S", "Silver" },
//		{ "B","Bronze" }
//	};
//}


int Account::creditLimit[4][3] = {
		{300,  600,  900},
		{500,  1000, 1500},
		{1000, 2000, 3000},
		{5000, 7000, 10000}
};

std::string Account::accountCategoryArr[4][2] = {
	{ "P","Platinum" },
	{ "G","Gold" },
	{ "S", "Silver" },
	{ "B","Bronze" }
};

Account::Account(int account_no, std::string f_name, std::string l_name, char account_category, int repayment_category, float balance_, std::string account_category_arr[4][2], int credit_limit[4][3]) {
	accountNumber = account_no;
	firstName = f_name;
	lastName = l_name;
	accountCategory = account_category;
	repaymentCategory = repayment_category;
	balance = balance_;

	// Copying values from account_category_arr to accountCategoryArr
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 2; ++j) {
			accountCategoryArr[i][j] = account_category_arr[i][j];
		}
	}

	// Copying values from credit_limit to creditLimit
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j) {
			creditLimit[i][j] = credit_limit[i][j];
		}
	}
}

void Account::setAccount(int account_no, std::string f_name, std::string l_name, char account_category, int repayment_category, float balance_) {
	accountNumber = account_no;
	firstName = f_name;
	lastName = l_name;
	accountCategory = account_category;
	repaymentCategory = repayment_category;
	balance = balance_;
	std::string accountCategoryArr[4][2] = {
		{ "P","Platinum" },
		{ "G","Gold" },
		{ "S", "Silver" },
		{ "B","Bronze" }
	};

	// Copying values from account_category_arr to accountCategoryArr
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 2; ++j) {
			accountCategoryArr[i][j] = accountCategoryArr[i][j];
		}
	}

	// Call readAndSetCreditLimits
	Account::readAndSetCreditLimits("creditlimits.csv");
};

void Account::readAndSetCreditLimits(std::string file_name) {
	std::fstream file;

	file.open(file_name);

	if (!file.is_open()) {
		std::cout << "File " << file_name << " could not be opened" << std::endl;
		exit(1);
	}

	std::string line;
	int counter = 0;

	while (!file.eof())
	{
		std::getline(file, line); // 300,600,900
		std::stringstream line_stream(line);

		std::string value;

		for (int i = 0; i < 3; i++) {
			std::getline(line_stream, value, ','); //300
			creditLimit[counter][i] == std::stoi(value);
		}
		counter++;
	}

	file.close();
};

int Account::determineCreditLimit() {
	int row = 0;
	for (int row_ = 0; row_ < 4; row_++) {
		if (accountCategoryArr[row_][0][0] == accountCategory) {
			row = row_;
			break;
		}
	}

	return creditLimit[row][repaymentCategory];
};


Account& Account::operator+(Transaction& new_transaction) {
	if (accountNumber != new_transaction.getTransactionAmnt()) {
		std::cout << "Cannot apply transaction – account numbers do not match" << std::endl;
		return;
	}

	if (new_transaction.getTransactionAmnt() < 0) { // it's a purchase
		//					300				100				500
		if ((this->determineCreditLimit() + (balance + new_transaction.getTransactionAmnt())) < 0) {
			std::cout << "Credit limit exceeded – transaction not applied" << std::endl;
			return;
		}

		balance = balance - new_transaction.getTransactionAmnt();
	}
	else {
		balance + new_transaction.getTransactionAmnt();
	}

	std::cout << "Transaction applied" << std::endl;
}

float Account::determineAmountPayable() {
	return balance;
}

float Account::getBalance() {
	return balance;
}

std::map<std::string, std::string> Account::getAccount() {
	/*account number, first
		name, surname and account category description of the account.*/
	std::map<std::string, std::string> account_data;

	account_data["account_number"] = std::to_string(accountNumber);
	account_data["f_name"] = firstName;
	account_data["l_name"] = lastName;
	account_data["account_category"] = std::to_string(accountCategory);

	// Find category row
	int row = 0;
	for (int row_ = 0; row_ < 4; row_++) {
		if (accountCategoryArr[row_][0][0] == accountCategory) {
			row = row_;
			break;
		}
	}

	account_data["account_description"] = accountCategoryArr[row][1];

	return account_data, account_data;
}


