#include "BankingAccount.h"
//#include <iostream>

void BankAccount::deposit(int amount)
{
	balance += amount;
	}

bool BankAccount::withdraw(int amount)
{
	if (amount <= balance)
	{
		balance -= amount;
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const account_state& obj)
{
	return os
		<< "initial_balance: " << obj.initial_balance
		<< "widhdraw_amount: " << obj.widhdraw_amount
		<< "final_balance: " << obj.final_balance
		<< "success: " << obj.success;

}