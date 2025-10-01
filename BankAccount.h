#include <iostream>
#include <vector>
#include "transaction.h"
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
class BankAccount
{
public:

	// Constructors
	BankAccount();
	BankAccount(std::string AccountNumber, std::string AccountHolderName, double Balance);
	BankAccount(const BankAccount& other);

	// Operators
	BankAccount& operator=(const BankAccount& other);
	BankAccount& operator+=(double amount);
	BankAccount& operator-=(double amount);
	bool operator==(const BankAccount& other) const;
	bool operator<(const BankAccount& other) const;
	bool operator>(const BankAccount& other) const;

	// Static function
	static void printAccount(const BankAccount& account);
	static BankAccount createAccountFromInput();

	// Class Functions
	void SetAccountHolderName(std::string AccountHolderName);
	void printHistory();
	virtual void Deposit(double amount);
	virtual void Withdraw(double amount);

	// Getters
	std::string GetAccountNumber();
	std::string GetAccountHolderName();
	double GetBalance();

	// Destructor
	virtual ~BankAccount();

protected:
	std::string accountNumber;
	std::string accountHolderName;
	double balance;
	std::vector<Transaction> transactionHistory;
};

#endif