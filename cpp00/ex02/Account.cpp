#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return (0);
}

int Account::getTotalAmount(void)
{
	return (0);
}

int Account::getNbDeposits(void)
{
	return (0);
}

int Account::getNbWithdrawals(void)
{
	return (0);
}

void Account::displayAccountsInfos(void)
{
	return ;
}

Account::Account(int initial_deposit)
{
	(void)initial_deposit;
}
Account::~Account(void)
{
}

void Account::makeDeposit(int deposit)
{
	(void)deposit;
	return ;
}

bool Account::makeWithdrawal(int withdawal)
{
	(void)withdawal;
	return (true);
}

int Account::checkAmount(void) const
{
	return (0);
}

void Account::displayStatus(void) const
{
	return ;
}

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm *t = std::localtime(&now);

	std::cout << "[" << (t->tm_year + 1900)
	 << std::setw(2) << std::setfill('0') << (t->tm_mon + 1) 
	 << std::setw(2) << std::setfill('0') << t->tm_mday 
	 << "_" 
	 << std::setw(2) << std::setfill('0') << t->tm_hour 
	 << std::setw(2) << std::setfill('0') << t->tm_min 
	 << std::setw(2) << std::setfill('0') << t->tm_sec 
	 << "]";
	return ;
}