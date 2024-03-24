#pragma once
#include"ques1_2.hpp"
#include<iostream>
#ifndef SixMonthAccount
#define SIXMONTACCOUTN

class SixMonthAccount : public Account
{
	static float clubFee;

public:
	//SixMonthAccount(int aN = 0, std::string fN = "", std::string sN = "", char aC = 'C', int rC = 1);
	static void setClubFee(float cF);
	float determineAmountPayable() const;
};

#endif SIXMONTACCOUTN


