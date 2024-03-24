#include "ques1_1.hpp"

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

int Transaction::getTransactionType() const
{
	return transactionType;
}