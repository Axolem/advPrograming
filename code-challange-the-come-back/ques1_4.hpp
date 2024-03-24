#pragma once
#include"ques1_1.hpp"
#include"ques1_2.hpp"
#include<iostream>
#ifndef TWELVEMONTHACCOUNT
#define TWELVEMONTHACCOUNT
class TwelveMonthAccount : public Account
{
	private:
	static float interestRate;

public:
	TwelveMonthAccount();
	TwelveMonthAccount(int, std::string, std::string, char, int, int);
	static void setInterestRate(float iR);
	float determineAmountPayable() const;
	float calculateInterest() const;
	//TwelveMonthAccount(float iR = 0.0);
};
#endif TWELVEMONTHACCOUNT

