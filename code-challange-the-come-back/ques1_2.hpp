#pragma once
#include<iostream>
#include<map>
#include"ques1_1.hpp"
#ifndef ACCOUNT
#define ACCOUNT
class Account
{
protected:
	int accountNumber;
	std::string firstName;
	std::string surname;
	char accountCategory;
	int repaymentCategory;

	float balance;
	static int creditLimit[4][3];
	static std::string accountCategoryName[4][2];



public:
	//Account();
	Account(int aN = 0, std::string fN = "", std::string sN = "", char aC = 'C', int rC = 1);

	void setAccount(int aN, std::string fN, std::string sN, char aC, int rC, float b);
	static void readAndSetCreditLimits(std::string file_name);
	int determineCreditLimit() const;
	void operator+(Transaction*);
	float determineAmountPayable() const;
	float getBalance() const;
	std::map<std::string, std::string> getAccount();

};

#endif ACCOUNT

