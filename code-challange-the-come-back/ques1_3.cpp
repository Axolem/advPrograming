#include "ques1_3.hpp"
#include "ques1_2.hpp"
#include "ques1_3.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

float SixMonthAccount::clubFee = 0.0;

void SixMonthAccount::setClubFee(float fee) {
	 clubFee = fee;
}

float SixMonthAccount::determineAmountPayable() const {
	float amount = balance / 6;

	if (amount < 100) {
		return 100 + clubFee;
	}
	else {
		return amount + clubFee;
	}
}

