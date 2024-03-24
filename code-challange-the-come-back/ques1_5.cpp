#include "ques1_1.hpp"
#include "ques1_2.hpp"
#include "ques1_3.hpp"
#include <cctype> 
#include<iostream>
#include <string> 

static int enterTransactions(Transaction* tr) {
	int accountNumber;
	int transactionType;
	float transactionAmount;
	int trans = 0;
	char answer = 'Y';

	while (toupper(answer) == 'Y') {
		std::cout << "For transaction " << trans + 1 << " enter:\n";
		std::cout << "\tAccount number: ";
		std::cin >> accountNumber;
		std::cout << "\tTransaction type (1 for payment,2 for purchase): ";
		std::cin >> transactionType;
		std::cout << "\tTransaction amount: R";
		std::cin >> transactionAmount;

		// Set the transaction here
		(tr + trans)->setTransaction(accountNumber, toupper(transactionType), transactionAmount);

		std::cout << "Do you want to enter another transaction? "
			<< "(Y for yes, N for no) ";
		std::cin >> answer;
		trans++;

		if (trans == 10) {
			std::cout << "You have reached the maximum number of transactions.\n";
			break;
		}
	}

	return trans;
}
const int MAXSIZE = 50;

static void enterAccount(Account* acc) {
	int accountNumber;
	char firstName[MAXSIZE];
	char surname[MAXSIZE];
	char accountCategory;
	int repaymentCategory;
	float balance;

	std::cout << "For the account enter:\n";
	std::cout << "\tAccount number: ";
	std::cin >> accountNumber;
	std::cout << "\tFirst name: ";
	std::cin >> firstName;
	std::cout << "\tSurname: ";
	std::cin >> surname;
	std::cout << "\tAccount Category:\n";
	std::cout << "\tEnter:\tP for Platinum\n";
	std::cout << "\tEnter:\tG for Gold\n";
	std::cout << "\tEnter:\tS for Silver\n";
	std::cout << "\tEnter:\tB for Bronze\n\t";
	std::cin >> accountCategory;
	std::cout << "Repayment Category (1, 2 or 3): ";
	std::cin >> repaymentCategory;
	std::cout << "Current Balance: R";
	std::cin >> balance;

	// Set the account here
	acc->setAccount(accountNumber, firstName, surname, accountCategory, repaymentCategory, balance);
}

static void displayAccount(Account* acc) {
	int accountNumber;
	char firstName[MAXSIZE];
	char surname[MAXSIZE];
	std::string accountCategory;
	float amntPayable;

	accountNumber = std::stoi(acc->getAccount()["account_number"]);
	amntPayable = acc->getBalance();
	accountCategory = acc->getAccount()["account_description"];
	strcpy_s(firstName, acc->getAccount()["first_name"].c_str());
	strcpy_s(surname, acc->getAccount()["surname"].c_str());

	std::cout << " Amount due for "
		<< accountCategory
		<< " account "
		<< accountNumber
		<< " - "
		<< firstName << " " << surname
		<< "is R"
		<< amntPayable << std::endl;
}
