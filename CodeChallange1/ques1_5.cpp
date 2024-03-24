#include"ques1_1.cpp"
#include"ques1_2.cpp"

int enterTransactions(Transaction* transactions) {
	int accountNumber;
	int transactionType;
	float transactionAmount;
	int trans = 0;
	char answer = 'Y';

	while (true)
	{
		std::cout << "For transaction " << trans + 1 << " enter:\n";
		std::cout << "\tAccount number: ";
		std::cin >> accountNumber;
		std::cout << "\tTransaction type (1 for payment,2 for purchase): ";
		std::cin >> transactionType;
		std::cout << "\tTransaction amount: R";
		std::cin >> transactionAmount;
		// Set the transaction here
		std::cout << "Do you want to enter another transaction? "
			<< "(Y for yes, N for no) ";
		std::cin >> answer;
		trans++;

		//Transaction new_transaction = Transaction();

		transactions[trans].setTransaction(accountNumber, transactionType, transactionAmount);

		//transactions[trans] = new_transaction;

		if(answer == 'y' || answer == 'Y' || trans == 10)
			break;
	}

	return trans;
}

const int MAXSIZE = 30;

void enterAccount(Account* account){
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
	std::cout << "Current Balance: ";
	std::cin >> balance;

	account->setAccount(accountNumber, firstName, surname, accountCategory, repaymentCategory, balance);
}

void displayAccount(Account* account ) {
	int accountNumber = std::stoi(account->getAccount()["account_number"]);
	char firstName[MAXSIZE];
	char surname[MAXSIZE];
	std::string accountCategory = account->getAccount()["account_category"];
	float amntPayable = account->determineAmountPayable();

	strcpy(firstName, account->getAccount()["f_name"].c_str());
	strcpy(surname, account->getAccount()["l_name"].c_str());

	std::cout	<< " Amount due for " 
				<< accountCategory 
				<< " account "
				<< accountNumber 
				<< " - "
				<< firstName << " "<< surname 
				<< "is" 
				<< amntPayable << std::endl;
}