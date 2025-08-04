/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 23:14:04 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/04 15:00:17 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

//how/where to init all 4 static at 0?

Account::Account( int initial_deposit ) {
	_displayTimestamp(); //[20250804_143025]
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;
	cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << endl;
}

Account::~Account( void ) {
	_displayTimestamp();
	cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << endl;
}

/*
	return "[%Y%m%d_%H%M%S]\0" to cout
*/
void Account::_displayTimestamp( void ) {
	time_t	*timer;
	struct tm *timeptr;
	char buff[18];
	string str;

	time(timer); //& instead?
	timeptr = localtime(timer);
	if (strftime(buff, 18, "[%Y%m%d_%H%M%S]", timeptr) == 0)
		cout << "Exceed maxsize chars." << endl;
	str = buff;
	cout << str;
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	//[19920104_091532] accounts:8;total:12442;deposits:8;withdrawals:6 endl
}

void Account::makeDeposit( int deposit ) {
	//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1 endl
}

bool Account::makeWithdrawal( int withdrawal ) {
	//[19920104_091532] index:0;p_amount:47;withdrawal:refused
	//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
}

void Account::displayStatus( void ) const {
	_displayTimestamp();
	//[19920104_091532] index:0;amount:47;deposits:1;withdrawals:0 endl
}