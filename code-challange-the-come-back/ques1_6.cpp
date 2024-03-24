#include"ques1_1.hpp"
#include"ques1_3.hpp"
#include"ques1_4.hpp"
#include"ques1_5.cpp"


int main() {

	Account* accPtr = nullptr;

	accPtr->readAndSetCreditLimits("creditlimits.csv");

	SixMonthAccount six;
	Transaction transactions[10];

	SixMonthAccount::setClubFee(12.50);

	enterAccount(&six);
	std::cout << "Credit limit: " << six.determineCreditLimit() << std::endl;

	int no_of_transactions = enterTransactions(transactions);


	for (int i = 0; i < no_of_transactions; i++) {
		six + &transactions[i];
	}

	displayAccount(&six);
	std::cout << "The amount payable is: R" << six.determineAmountPayable() << std::endl;

	TwelveMonthAccount twelve;

	accPtr = &twelve;

	accPtr->setAccount(123, "John", "Doe", 'P', 1, 1000.0);
	TwelveMonthAccount::setInterestRate(15.5);
	displayAccount(accPtr);

	std::cout << "The amount payable is: R" << accPtr->determineAmountPayable() << std::endl;

	system("pause");
	return 0;
}
