/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 23:14:04 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/06 10:10:34 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

# include <iostream>
# include <string>
# include <algorithm>
# include <functional>
# include <cstdio>
# include <ctime>

Account::Account( int initial_deposit ) {
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

/*
	return "[%Y%m%d_%H%M%S]\0" to cout
*/
void Account::_displayTimestamp( void ) {
	time_t	*timer;
	struct tm *timeptr;
	char buff[18];
	std::string str;

	time(timer); //& instead?
	timeptr = localtime(timer);
	if (strftime(buff, 18, "[%Y%m%d_%H%M%S]", timeptr) == 0)
		std::cout << "Exceed maxsize chars." << std::endl;
	str = buff;
	std::cout << str;
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
	//[19920104_091532] accounts:8;total:12442;deposits:8;withdrawals:6 endl
}

void Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount 
		<< ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << ++_nbDeposits << std::endl;
	//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1 endl
}

bool Account::makeWithdrawal( int withdrawal ) {
	int p_amount;

	p_amount = _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << p_amount;
	p_amount = (_amount - withdrawal);
	if ((p_amount) < 0)
		std::cout << ";withdrawal:refused";
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << ";amount:" << _amount << ";nb_withdrawals:" << ++_nbDeposits << std::endl;
	}
	//[19920104_091532] index:0;p_amount:47;withdrawal:refused
	//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
}

void Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
	//[19920104_091532] index:0;amount:47;deposits:1;withdrawals:0 endl
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
