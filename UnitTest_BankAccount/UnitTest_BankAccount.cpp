#include "gtest/gtest.h"
#include "BankingAccount.cpp"


//test fixture
struct BankAccountTest : testing::Test
{
	BankAccount* account;

	BankAccountTest()
	{
		account = new BankAccount;
	}

	 virtual ~BankAccountTest()
	{
		delete account;
	}
	
};

struct WithdrawAccountTest : BankAccountTest,
	testing::WithParamInterface<account_state>
{
	WithdrawAccountTest()
	{
		account->balance = GetParam().initial_balance;
	}
};




TEST_F(BankAccountTest, BankAccountStartsEmpty)
{

	EXPECT_EQ(0, account->balance);
}

TEST_F(BankAccountTest, CanDepositMoney)
{
	account->deposit(100);
	EXPECT_EQ(100, account->balance);
}

TEST_P(WithdrawAccountTest, FinalBalance)
{
	auto as = GetParam();
	auto success = account->withdraw(as.widhdraw_amount);
	EXPECT_EQ(as.final_balance, account->balance);
	EXPECT_EQ(as.success, success);
}


INSTANTIATE_TEST_CASE_P(Default, WithdrawAccountTest,
	testing::Values(
		account_state{ 100,50,50,true },
		account_state{ 100,200,100,false }
));
