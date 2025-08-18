/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filestream.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:08:42 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/18 10:05:00 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILESTREAM_HPP
# define FILESTREAM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>

class Filestream {

	public:
		Filestream( const std::string filename,
			const std::string s1,
			const std::string s2 );
		~Filestream();

		const std::string	inContent( void );
		const std::string	replaceContent( const std::string &content );
		void				outContent( const std::string result );

	private:
		std::ifstream			_ifs;
		std::ofstream			_ofs;
		std::stringstream		_buff;

		const std::string		_filename;
		const std::string		_s1;
		const std::string		_s2;

};

#endif