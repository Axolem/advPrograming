#include<iostream>
#include"ques1_3.cpp"
#include"ques1_4.cpp"
#include"ques1_5.cpp"


int main() {

	SixMonthAccount six;
	Transaction* transaction = new Transaction[10];

	SixMonthAccount::setClubFee(12.50);

	int no_of_trans = enterTransactions(transaction);
	enterAccount(&six);

	for (int i = 0; i < no_of_trans; i++) {
		six + transaction[i];
	}

	std::system("pause");
	return 0;
}