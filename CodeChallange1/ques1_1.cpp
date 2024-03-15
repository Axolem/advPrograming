#include <iostream>
#ifndef TRANSACTION


class Transaction
{
private:
	int accountNumber;
	int transactionType;
	float transactionAmount;
public:
	Transaction(int aN = 0, int tT = 1, float tA = 0.0);
	void setTransaction(int aN, int tT, float tA);
	int getAccountNumber() const;
	float getTransactionAmnt() const;
};



Transaction::Transaction(int aN, int tT, float tA)
{
	accountNumber = aN;
	transactionType = tA;
	transactionAmount = tA;
}



void Transaction::setTransaction(int aN, int tT, float tA)
{
	accountNumber = aN;
	transactionType = tT;
	transactionAmount = tA;
}



int Transaction::getAccountNumber() const
{
	return accountNumber;
}



float Transaction::getTransactionAmnt() const
{
	switch (transactionType)
	{
	case 1: return -transactionAmount;
		break;
	case 2: return transactionAmount;
	}
}

#endif