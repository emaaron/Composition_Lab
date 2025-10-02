# Bank Account class
A simple C++ program using classes and vectors for storing banking information from specific users using their Bank name, Bank Number, and Bank balance.

### Data Dictionary
|	Attribute	|	Data Type	|	Description	|	
|---------------|---------------|---------------|
|`accountNumber`|`std::string`|Account number for each Bank Account.
|`accountHolderName`|`std::string`|Account name for each Bank Account.
|`balance`|`double`|balance of each Bank Account.

### Methods List
|	Method Signature	|	Return Type	| Description
|---------------|---------------|---------------
|`BankAccount()`|`Constructor`| Default constructor.
|`BankAccount()`|`Constructor`|Parameterized constructor.
|`SetAccountHolderName()`|`void`|Sets `accountHolderName` from the parameter.
|`Deposit()`|`void`|Adds parameter amount to `balance`.
|`Withdraw()`|`void`|Removes amount from parameter to `balance`.
|`GetAccountNumber()`|`std::string`|returns value from `accountNumber`.
|`GetAccountHolderName()`|`std::string`|returns value from `accountHolderName`.
|`GetBalance()`|`double`|returns value from `balance`
> Aaron Vasquez
