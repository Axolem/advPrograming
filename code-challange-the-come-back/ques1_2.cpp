#include "ques1_2.hpp"
#include "ques1_3.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

int Account::creditLimit[4][3] = {
		{300,  600,  900},
		{500,  1000, 1500},
		{1000, 2000, 3000},
		{5000, 7000, 10000}
};

std::string Account::accountCategoryName[4][2] = {
	{ "P","Platinum" },
	{ "G","Gold" },
	{ "S", "Silver" },
	{ "B","Bronze" }
};

Account::Account(int aN, std::string fN, std::string sN, char aC, int rC) {
	accountNumber = aN;
	firstName = fN;
	surname = sN;
	accountCategory = aC;
	repaymentCategory = rC;
	balance = 0.0;
}

void Account::setAccount(int aN = 0, std::string fN = "", std::string sN = "", char aC = 'C', int rC = 1, float b = 0) {
	accountNumber = aN;
	firstName = fN;
	surname = sN;
	accountCategory = aC;
	repaymentCategory = rC;
	balance = b;

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
			creditLimit[counter][i] = std::stoi(value);
		}
		counter++;
	}

	file.close();
};

int Account::determineCreditLimit() const {
	int row = 0;
	for (int row_ = 0; row_ < 4; row_++) {
		if (accountCategoryName[row_][0][0] == accountCategory) {
			row = row_;
			break;
		}
	}

	return creditLimit[row][repaymentCategory - 1];
};


void Account::operator  + (Transaction* new_transaction) {

	if (accountNumber != new_transaction->getAccountNumber()) {
		std::cout << "Cannot apply transaction – account numbers do not match" << std::endl;
		return;
	}

	float transactionAmount = new_transaction->getTransactionAmnt();

	if (transactionAmount > determineCreditLimit() + balance) {
		std::cout << "Cannot apply transaction – credit limit exceeded" << std::endl;
	}
	else {
		std::cout << transactionAmount + balance << std::endl;
		this->balance = transactionAmount + balance;
		std::cout << "Transaction applied" << std::endl;
	}

	std::cout << balance << std::endl;
}

float Account::determineAmountPayable() const {
	return balance;
}

float Account::getBalance() const {
	return balance;
}

std::map<std::string, std::string> Account::getAccount() {
	/*account number, first
		name, surname and account category description of the account.*/
	std::map<std::string, std::string> account_data;

	account_data["account_number"] = std::to_string(accountNumber);
	account_data["first_name"] = firstName;
	account_data["surname"] = surname;
	account_data["account_category"] = std::to_string(accountCategory);

	// Find category row
	int row = 0;
	for (int row_ = 0; row_ < 4; row_++) {
		if (accountCategoryName[row_][0][0] == accountCategory) {
			row = row_;
			break;
		}
	}

	account_data["account_description"] = accountCategoryName[row][1];

	return account_data;
}