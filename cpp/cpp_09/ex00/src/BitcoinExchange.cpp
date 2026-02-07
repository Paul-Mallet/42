/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:43:07 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/07 15:20:16 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void ) {
	std::cout << "BitcoinExchange - Default Constructor\n" << std::endl;
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src ) : _db(src._db) {
	std::cout << "BitcoinExchange - Copy Constructor\n" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "\nBitcoinExchange - Destructor" << std::endl;
}

BitcoinExchange & BitcoinExchange::operator=( BitcoinExchange const & rhs ) {
	if (this != &rhs) {
		this->_db = rhs._db;
	}
	return (*this);
}

std::map<std::string, float> BitcoinExchange::getDatabase( void ) const {
	return (this->_db);
}

/**
 * @brief Utils functions grouped at top of member functions.
 */
static std::string trim( const std::string & str ) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
		return ("");

    size_t last = str.find_last_not_of(" \t\n\r");
    return (str.substr(first, (last - first + 1)));
}

static int validateYear( std::stringstream & ss, std::string const & y_str, unsigned int & ln ) {
	int y_value;

	ss.str(y_str);
	if (!(ss >> y_value)) {
		std::cout << "Error: not a valid year number => " << y_str << "   at l." << ++ln << std::endl;
		return (-1);
	}
	return (y_value);
}

static int validateMonth( std::stringstream & ss, std::string const & m_str, unsigned int & ln ) {
	int m_value;

	ss.clear();
	ss.str(m_str);
	if (!(ss >> m_value)) {
		std::cout << "Error: not a valid month number => " << m_str << "   at l." << ++ln << std::endl;
		return (-1);
	}
	if (m_value < 1 || m_value > 12) {
		std::cout << "Error: invalid month, must be between 1 & 12 => " << m_str << "   at l." << ++ln << std::endl;
		return (-1);
	}
	return (m_value);
}

static int validateDay( std::stringstream & ss, std::string const & d_str, unsigned int & ln, int & y_value, int & m_value ) {
	int d_value;
	int maxDay = 0;

	ss.clear();
	ss.str(d_str);
	if (!(ss >> d_value)) {
		std::cout << "Error: not a valid day number => " << d_str << "   at l." << ++ln << std::endl;
		return (-1);
	}
	if (m_value == 4 || m_value == 6 || m_value == 9 || m_value == 11)
		maxDay = 30;
	else if (m_value == 2 && ( ((y_value % 4 == 0) && (y_value % 100 != 0)) || ( y_value % 400 == 0 ) ))
		maxDay = 29;
	else if (m_value == 2)
		maxDay = 28;
	else
		maxDay = 31;
	if (d_value < 1 || d_value > maxDay) {
		std::cout << "Error: invalid day, must be between 1 & 31 => " << d_str << "   at l." << ++ln << std::endl;
		return (-1);
	}
	return (true);
}

/**
 * @brief Member functions.
 */
void BitcoinExchange::loadDatabase( const std::string & dbPath ) {
	std::ifstream ifs;

	ifs.open(dbPath.c_str());
	if (ifs.is_open()) {
		std::string line;

		unsigned long size = 0;

		while (getline(ifs, line))
			++size;
		if (size >= std::numeric_limits<u_int>::max()) {
			std::cout << "File size to big, must be < 4Bn lines" << std::endl;
			return ;
		}
		ifs.clear();
		ifs.seekg(0, ifs.beg);

		getline(ifs, line);
		while (getline(ifs, line)) {
			size_t sep = line.find(',');
			if (sep != std::string::npos) {
				std::string date = line.substr(0, sep);
				float exchange_rate = std::atof(line.substr(sep + 1).c_str());

				this->_db.insert( std::pair<std::string, float>(date, exchange_rate) );
			}
		}
	}
	else {
		std::cout << "Failed to open data.csv" << std::endl;
	}
	ifs.close();
}

bool BitcoinExchange::validateDate( const std::string & date, unsigned int & ln ) {
	if (date.size() != 10) {
		std::cout << "Error: invalid length date => " << date << " (" << date.size() << ")" << "   at l." << ++ln << std::endl;
		return (false);
	}
	if (date[4] != '-' || date[7] != '-') {
		std::cout << "Error: invalid format date, '-' is missing => " << date << "   at l." << ++ln << std::endl;
		return (false);
	}

	std::string y_str = date.substr(0, 4);
	std::string m_str = date.substr(5, 2);
	std::string d_str = date.substr(8);
	size_t bad_occurence;
	bad_occurence = y_str.find_first_not_of("0123456789");
	if (bad_occurence != std::string::npos) {
		std::cout << "Error: invalid format date, digit(s) is missing on year => " << y_str << "   at l." << ++ln << std::endl;
		return (false);
	}
	bad_occurence = m_str.find_first_not_of("0123456789");
	if (bad_occurence != std::string::npos) {
		std::cout << "Error: invalid format date, digit(s) is missing on month => " << m_str << "   at l." << ++ln << std::endl;
		return (false);
	}
	bad_occurence = d_str.find_first_not_of("0123456789");
	if (bad_occurence != std::string::npos) {
		std::cout << "Error: invalid format date, digit(s) is missing on day => " << d_str << "   at l." << ++ln << std::endl;
		return (false);
	}

	int y_value, m_value;
	std::stringstream ss;

	y_value = validateYear(ss, y_str, ln);
	if (y_value < 0)
		return (false);
	m_value = validateMonth(ss, m_str, ln);
	if (m_value < 0)
		return (false);
	if (validateDay(ss, d_str, ln, y_value, m_value) < 0)
		return (false);
	return (true);
}

bool BitcoinExchange::validateValue( const std::string & valueStr, float & value, unsigned int & ln ) {
	std::stringstream ss(valueStr);

    if (!(ss >> value)) {
        std::cout << "Error: not a valid value => " << valueStr << "   at l." << ++ln << std::endl;
        return false;
    }

    std::string extra;
    if (ss >> extra) {
        std::cout << "Error: not a valid value => " << valueStr << "   at l." << ++ln << std::endl;
        return false;
    }

	if (value < 0 || valueStr[0] == '-') {
        std::cout << "Error: not a positive value => " << valueStr << "   at l." << ++ln << std::endl;
        return false;
    }
    if (value > 1000) {
        std::cout << "Error: value must not be greater than 1000 => " << valueStr << "   at l." << ++ln << std::endl;
        return false;
    }
	++ln;
	return (true);
}

void	BitcoinExchange::executeExchange( const std::string & date, float & value ) {
	std::map<std::string, float>::iterator it = this->_db.lower_bound(date);

	if (it == _db.begin() && it->first != date) {
    	std::cout << "Error: date too early => " << date << " (No historical data)" << std::endl;
    	return ;
	}

	if (it == this->_db.end())
		it--;

	std::cout << date << " => " << value << " = " << ( it->second * value ) << std::endl;
}

void BitcoinExchange::processInput( const std::string & inputPath ) {
	std::ifstream ifs;

	ifs.open(inputPath.c_str());
	if (ifs.is_open()) {
		std::string		line;
		unsigned long size = 0;

		while (getline(ifs, line))
			++size;
		if (size >= std::numeric_limits<u_int>::max()) {
			std::cout << "File size to big, must be < 4Bn lines" << std::endl;
			return ;
		}
		ifs.clear();
		ifs.seekg(0, ifs.beg);
		unsigned int	ln = 1;

		getline(ifs, line);
		while (getline(ifs, line)) {
			size_t sep = line.find('|');
			if (sep == std::string::npos) {
				std::cout << "Error: '|' is missing => " << line << "   at l." << ++ln << std::endl;
				continue ;
			}

			std::string date = trim(line.substr(0, sep));
			std::string value_str = trim(line.substr(sep + 1).c_str());
			float value = -1;
			if (!this->validateDate(date, ln) || !this->validateValue(value_str, value, ln))
				continue ;
			else
				this->executeExchange(date, value);
		}
	}
	else {
		std::cout << "Failed to open input file" << std::endl;
	}
	ifs.close();
}