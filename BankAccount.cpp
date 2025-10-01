#include <iostream>
#include <string>
#include <limits>
#include <ctime> // https://www.w3schools.com/cpp/cpp_date.asp (Source for helping with timestamp)
#include "BankAccount.h"

/*----------[Constructors]----------*/

// Default Constructor
BankAccount::BankAccount()
{
	accountNumber = "";
	accountHolderName = "";
	balance = 0.00;
}

// Parameterized Constructor
BankAccount::BankAccount(std::string AccountNumber, std::string AccountHolderName, double Balance)
{
	accountNumber = AccountNumber;
	accountHolderName = AccountHolderName;
	balance = Balance;
}

// Constructor
BankAccount::BankAccount(const BankAccount& other) {
	accountNumber = other.accountNumber;
	accountHolderName = other.accountHolderName;
	balance = other.balance;
}

/*--------------------*/

/*----------[Operators]----------*/
BankAccount& BankAccount::operator=(const BankAccount& other)
{
	if (this != &other)
	{
		accountNumber = other.accountNumber;
		accountHolderName = other.accountHolderName;
		balance = other.balance;
	}
	return *this;
}

BankAccount& BankAccount::operator+=(double amount)
{
	balance += amount;
	return *this;
}

BankAccount& BankAccount::operator-=(double amount)
{
	balance -= amount;
	return *this;
}

bool BankAccount::operator==(const BankAccount& other) const
{
	return (accountNumber == other.accountNumber &&
		accountHolderName == other.accountHolderName &&
		balance == other.balance);
}

bool BankAccount::operator<(const BankAccount& other) const
{
	return (balance < other.balance);
}

bool BankAccount::operator>(const BankAccount& other) const
{
	return (balance > other.balance);
}

/*--------------------*/

/*----------[Static function]----------*/
void BankAccount::printAccount(const BankAccount& account)
{
	std::cout << "Bank Info:"
		<< "\nAccount Name: " << account.accountHolderName
		<< "\nAccount Number: " << account.accountNumber
		<< "\nCurrent Balance: $" << account.balance
		<< std::endl;
	return;
}

BankAccount BankAccount::createAccountFromInput()
{
	BankAccount createAccount;
	int accountNum;
	double balance;
	std::string accountName;

	std::cout << "Define a account number for the Bank Account." << std::endl;

	std::cout << "> ";

	while (!(std::cin >> accountNum))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "> ";
	}
	std::cout << std::endl;

	std::cout << "Define a account name for the Bank Account." << std::endl;
	std::cout << "> ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, accountName);
	std::cout << std::endl;

	std::cout << "Define a starting balance for the Bank Account." << std::endl;

	std::cout << "$ ";
	while (!(std::cin >> balance))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "$ ";
	}

	std::cout << std::endl;

	createAccount.SetAccountHolderName(accountName);
	createAccount = BankAccount(std::to_string(accountNum), createAccount.GetAccountHolderName(), balance);
	return createAccount;
}

/*--------------------*/

/*----------[Class Functions]----------*/
void BankAccount::SetAccountHolderName(std::string AccountHolderName)
{
	accountHolderName = AccountHolderName;
	return;
}

void BankAccount::printHistory()
{
	if (transactionHistory.empty())
	{
		std::cout << "There is no transaction found." << std::endl;
	}
	else
	{
		std::cout << accountHolderName << "'s transactions history:" << std::endl;
		for (int i = 0; i < transactionHistory.size(); i++)
		{
			std::cout << "Type: " << transactionHistory.at(i).type
				<< "\nAmount: $" << transactionHistory.at(i).amount
				<< "\nDate: " << transactionHistory.at(i).timestamp
				<< std::endl;
			std::cout << std::endl;
		}
	}
}

void BankAccount::Deposit(double amount)
{
	if (amount == 0)
	{
		std::cout << "Your balance did not change cause of invalid amount of 0." << std::endl;
	}
	else if (amount < 0)
	{
		std::cout << "Invalid amount of money to deposit." << std::endl;
	}
	else {
		*this += amount;
		Transaction deposit;
		deposit.type = "Deposit";
		deposit.amount = amount;

		// Time
		std::time_t timestamp;
		std::time(&timestamp);
		deposit.timestamp = ctime(&timestamp);

		// Push transaction information into vector
		transactionHistory.push_back(deposit);

		std::cout << "New account balance: $" << balance << std::endl;
	}
}

void BankAccount::Withdraw(double amount)
{
	if (amount == 0)
	{
		std::cout << "Your balance did not change cause of invalid amount of 0." << std::endl;
	}
	else if (amount < 0)
	{
		std::cout << "Invalid amount of money to withdraw." << std::endl;
	}
	else if (amount > balance)
	{
		std::cout << "Not enough funds." << std::endl;
	}
	else {
		*this -= amount;

		Transaction withdraw;
		withdraw.type = "Withdraw";
		withdraw.amount = amount;

		// Time
		std::time_t timestamp;
		std::time(&timestamp);
		withdraw.timestamp = ctime(&timestamp);

		// Push transaction information into vector
		transactionHistory.push_back(withdraw);

		std::cout << "New account balance: $" << balance << std::endl;
	}
}
/*--------------------*/

/*----------[Getters]----------*/
std::string BankAccount::GetAccountNumber()
{
	return accountNumber;
}

std::string BankAccount::GetAccountHolderName()
{
	return accountHolderName;
}

double BankAccount::GetBalance()
{
	return balance;
}

/*--------------------*/

/*----------[Destructor]----------*/
BankAccount::~BankAccount() {}
/*--------------------*/