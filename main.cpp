/*
*	Name: Aaron Vasquez
*	Date: October 1, 2025
*	Program Purpose: Improved banking system using inheritance and composition along with adding transaction history.
*	Assignment: Lab Activities: Inheritance & Composition
*/

// Imported header files
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

// Imported libraries
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <memory>

// Main function
int main()
{
	// Vectors
	BankAccount a_bank;
	std::vector<std::unique_ptr<BankAccount>> accountList;

	// Main variables
	int option, accountOption, accountNum;
	double fee, rate;
	std::string accountName;
	bool found = false;
	double amount;

	// Main program loop (loops until 6 is entered into option variable)
	do {
		std::cout << "[Choose a option!]"
			<< "\n1. Open Account"
			<< "\n2. See Account"
			<< "\n3. Deposit"
			<< "\n4. Withdraw"
			<< "\n5. Transaction history"
			<< "\n6. Apply Interest"
			<< "\n7. Quit"
			<< std::endl;

		// Input [option] with input checking for only numbers
		std::cout << "> ";
		while (!(std::cin >> option))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "> ";
		}
		std::cout << std::endl;

		// Option handler (switch-cases)
		switch (option)
		{
		case 1: // Option 1 (Creating account)
			a_bank = BankAccount::createAccountFromInput();

			std::cout << "What account type would this be?"
				<< "\n1) Checking account"
				<< "\n2) Savings account"
				<< std::endl;

			std::cout << "> ";

			while (!(std::cin >> accountOption))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "> ";
			}

			std::cout << std::endl;

			found = false;

			for (int i = 0; i < accountList.size(); i++)
			{
				if (accountList.at(i).get()->GetAccountNumber() == a_bank.GetAccountNumber() == true)
				{
					found = true;
				}
			}

			if (found == false)
			{
				if (accountOption == 1)
				{
					std::cout << "Enter a transaction fee for the account." << std::endl;
					std::cout << "$ ";

					while (!(std::cin >> fee))
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "$ ";
					}
					accountList.push_back(std::make_unique<CheckingAccount>(a_bank.GetAccountNumber(), a_bank.GetAccountHolderName(), a_bank.GetBalance(), fee));
				}
				else if (accountOption == 2)
				{
					std::cout << "Enter a interest rate for the account." << std::endl;
					std::cout << "$ ";

					while (!(std::cin >> rate))
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "$ ";
					}
					accountList.push_back(std::make_unique<SavingsAccount>(a_bank.GetAccountNumber(), a_bank.GetAccountHolderName(), a_bank.GetBalance(), rate));
				}
				else
				{
					std::cout << "Invalid account type!" << std::endl;
				}
			}
			else {
				std::cout << "Account number already exists to someone." << std::endl;
			}
			std::cout << std::endl;
			break;
		case 2: // Option 2 (See Account)
			if (accountList.empty())
			{
				std::cout << "Sorry but there are no accounts registered." << std::endl;
			}
			else
			{

				std::cout << "Please enter in your account number." << std::endl;
				std::cout << "> ";

				while (!(std::cin >> accountNum))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "> ";
				}
				std::cout << std::endl;

				found = false;
				for (int i = 0; i < accountList.size(); i++)
				{
					if (accountList.at(i).get()->GetAccountNumber() == std::to_string(accountNum))
					{
						found = true;
						BankAccount::printAccount(*accountList.at(i));
					}
				}
				if (found == false)
				{
					std::cout << "Account was not found!" << std::endl;
				}
			}
			std::cout << std::endl;
			break;
		case 3: // Option 3 (Deposit)

			if (accountList.empty())
			{
				std::cout << "Sorry but there are no accounts registered." << std::endl;
			}
			else
			{
				std::cout << "Please enter in your account number." << std::endl;
				std::cout << "> ";

				while (!(std::cin >> accountNum))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "> ";
				}
				std::cout << std::endl;

				found = false;
				for (int i = 0; i < accountList.size(); i++)
				{
					if (accountList.at(i).get()->GetAccountNumber() == std::to_string(accountNum))
					{
						found = true;
						std::cout << "How much would you like to deposit?" << std::endl;
						std::cout << "$ ";
						while (!(std::cin >> amount))
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cout << "$ ";
						}
						std::cout << std::endl;
						accountList.at(i).get()->Deposit(amount);
					}
				}

				if (found == false)
				{
					std::cout << "Account was not found!" << std::endl;
				}
			}
			std::cout << std::endl;
			break;
		case 4: // Option 4 (Withdraw)
			if (accountList.empty())
			{
				std::cout << "Sorry but there are no accounts registered." << std::endl;
			}
			else
			{
				std::cout << "Please enter in your account number." << std::endl;
				std::cout << "> ";
				while (!(std::cin >> accountNum))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "> ";
				}
				std::cout << std::endl;
				found = false;
				for (int i = 0; i < accountList.size(); i++)
				{
					if (accountList.at(i).get()->GetAccountNumber() == std::to_string(accountNum))
					{
						found = true;
						std::cout << "How much would you like to withdraw?" << std::endl;

						std::cout << "$ ";
						while (!(std::cin >> amount))
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cout << "$ ";
						}
						std::cout << std::endl;
						accountList.at(i).get()->Withdraw(amount);
					}
				}
				if (found == false)
				{
					std::cout << "Account was not found!" << std::endl;
				}
			}
			std::cout << std::endl;
			break;
		case 5: // Option 5 (Transaction history)
			if (accountList.empty())
			{
				std::cout << "Sorry but there are no accounts registered." << std::endl;
			}
			else
			{
				std::cout << "Please enter in your account number." << std::endl;
				std::cout << "> ";
				while (!(std::cin >> accountNum))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "> ";
				}
				std::cout << std::endl;
				found = false;
				for (int i = 0; i < accountList.size(); i++)
				{
					if (accountList.at(i).get()->GetAccountNumber() == std::to_string(accountNum))
					{
						found = true;
						accountList.at(i).get()->printHistory();
					}
				}
				if (found == false)
				{
					std::cout << "Account was not found!" << std::endl;
				}
			}
			std::cout << std::endl;
			break;
		case 6: // Option 6 (Apply Interest)
			if (accountList.empty())
			{
				std::cout << "Sorry but there are no accounts registered." << std::endl;
			}
			else
			{
				std::cout << "Please enter in your account number." << std::endl;
				std::cout << "> ";
				while (!(std::cin >> accountNum))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "> ";
				}
				std::cout << std::endl;

				found = false;
				for (int i = 0; i < accountList.size(); i++)
				{
					if (accountList.at(i).get()->GetAccountNumber() == std::to_string(accountNum))
					{
						found = true;
						SavingsAccount* SavingsInterestAccount = dynamic_cast<SavingsAccount*>(accountList.at(i).get());
						if (SavingsInterestAccount)
						{
							SavingsInterestAccount->calculateInterest();
						}
						else
						{
							std::cout << "Account is not a savings account." << std::endl;
						}
					}
				}
				if (found == false)
				{
					std::cout << "Account was not found!" << std::endl;
				}
			}
			std::cout << std::endl;
			break;
		default:
			continue; // Return back to menu screen if option number isn't defined in the switch-cases
		}

	} while (option != 7); // End loop and end program once option is equal to 7

	return 0;
}