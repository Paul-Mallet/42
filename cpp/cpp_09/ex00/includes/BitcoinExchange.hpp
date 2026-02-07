/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:35:44 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/07 15:29:09 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <sstream>
# include <fstream>
# include <cstdlib>
# include <string>
# include <limits>
# include <map>

class BitcoinExchange {

	private:
		std::map<std::string, float> _db;

	public:
		BitcoinExchange( void );
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();

		BitcoinExchange & operator=( BitcoinExchange const & rhs );

		std::map<std::string, float> getDatabase( void ) const;

		/**
		 * @brief Try to open and read from the data.csv file to stock it within this->_db;
		 */
		void	loadDatabase( const std::string & dbPath );
		/**
		 * @brief Try to open and read from the input.txt file to process the exchange rate;
		 */
		void	processInput( const std::string & inputPath );
		bool	validateDate( const std::string & date, unsigned int & ln );
        bool	validateValue( const std::string & valueStr, float & value, unsigned int & ln );
		void	executeExchange( const std::string & date, float & value );

};

#endif