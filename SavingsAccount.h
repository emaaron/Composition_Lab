#include "BankAccount.h"
#include <iostream>
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount : public BankAccount {
public:

	// Constructors
	SavingsAccount(std::string AccountNumber, std::string AccountHolderName, double Balance, double Rate);

	// Class Functions
	void calculateInterest();

	// Destructor
	~SavingsAccount();

private:
	double interestRate;
};

#endif
