#include "BankAccount.h"
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

class CheckingAccount : public BankAccount {
public:

	// Constructors
	CheckingAccount(std::string AccountNumber, std::string AccountHolderName, double Balance, double fee);

	// Class Functions
	void Withdraw(double amount) override;

	// Destructor
	~CheckingAccount();

private:
	double transactionFee;
};

#endif
