#pragma once
#include <iostream>
struct BankAccount
{
	int balance = 0;

	BankAccount()
	{

	}

	explicit BankAccount(const int balance)
		:balance{ balance }
	{

	}
	void deposit(int amount);
	bool withdraw(int amount);
	
};

struct account_state
{
	int initial_balance;
	int widhdraw_amount;
	int final_balance;
	bool success;

	friend std::ostream& operator<<(std::ostream& os, const account_state& obj);
	
};







