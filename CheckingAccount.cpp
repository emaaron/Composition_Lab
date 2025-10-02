#include "CheckingAccount.h"
#include <iostream>
#include <ctime> // https://www.w3schools.com/cpp/cpp_date.asp (Source for helping with timestamp)

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

		Transaction history;
		history.type = "Withdraw";
		history.amount = amount;

		std::time_t timestamp;
		std::time(&timestamp);
		history.timestamp = ctime(&timestamp);
		transactionHistory.push_back(history);

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