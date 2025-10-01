#include "SavingsAccount.h"
#include <iostream>

/*----------[Constructors]----------*/
SavingsAccount::SavingsAccount(std::string AccountNumber, std::string AccountHolderName, double Balance, double Rate)
{
	accountNumber = AccountNumber;
	accountHolderName = AccountHolderName;
	balance = Balance;
	interestRate = Rate;
}
/*--------------------*/

/*----------[Class Functions]----------*/
void SavingsAccount::calculateInterest()
{
	double interest = balance * interestRate;
	balance += interest;
	std::cout << "Interest added: $" << interest
		<< "\nBalance: $" << balance
		<< std::endl;
}
/*--------------------*/

/*----------[Destructor]----------*/
SavingsAccount::~SavingsAccount() {}
/*--------------------*/