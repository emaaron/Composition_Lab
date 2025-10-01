#include <iostream>
#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction {
public:
	std::string type;
	double amount;
	std::string timestamp;
};

#endif