#pragma once
#include<iostream>
#ifndef TRANSACTION
#define TRANSACTION
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
	int getTransactionType() const;
};
#endif