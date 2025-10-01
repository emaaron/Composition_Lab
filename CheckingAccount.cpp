#include "CheckingAccount.h"
#include <iostream>

/*----------[Constructors]----------*/

CheckingAccount::CheckingAccount(std::string AccountNumber, std::string AccountHolderName, double Balance, double fee)
{
	accountNumber = AccountNumber;
	accountHolderName = AccountHolderName;
	balance = Balance;
	transactionFee = fee;
}
/*--------------------*/

/*----------[Class Functions]----------*/

void CheckingAccount::Withdraw(double amount)
{
	double total = amount + transactionFee;
	if (total > balance)
	{
		std::cout << "Not enough funds (including transaction fee)" << std::endl;
	}
	else
	{
		balance -= total;
		std::cout << "Withdrew: $" << amount
			<< "\nFee: $" << transactionFee
			<< "\nCurrent Balance: $" << balance
			<< std::endl;
	}
	return;
}

/*--------------------*/

/*----------[Destructor]----------*/
CheckingAccount::~CheckingAccount() {}
/*--------------------*/