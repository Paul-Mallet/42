/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 09:44:50 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/17 14:37:29 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
/*
	std::ifstream:
		//...
		clear() -> reset flag on state's error
		seekg(0, std::ios::beg) -> reset read pos at file's beginning
	std::ofstream:
		//...
	states(flags):
		good() -> goodbit: no error
		eof() -> eofbit: while performing an extracting operation(CTRL+C/D...) on stream
		fail() -> failbit: input logical, parsing error
		bad() -> badbit: irrecoverable error(Disk errors(full during write), Network issues(co drops), Permission changes(file perms revokes while stream is open), Device removal(USB drive unplugged)...)
	//read file
	std::string:
		substr(pos, len) -> return new Object sub string based on start pos and spans len characters/until end of string
		find() ->
*/
int main( int ac, char **av )
{
	std::ifstream file;
	std::string s1;
	std::string s2;
	std::stringstream buff;
	std::string content;
	std::string result;
	std::string::size_type found;
	std::string::size_type pos;

	// check input basic formats
	if (ac != 4)
	{
		std::cout << "Format required: ./streamfile <filename> s1 s2\n";
		return 0;
	}

	//stock in string
	s1 = av[2];
	s2 = av[3];

	// check stream state after opened file
	file.open(av[1], std::ifstream::in);
	if (!file.is_open())
	{
		std::cerr << "Error: Cannot open file.\n";
		return 0;
	}
	if (file.fail())
	{
		std::cerr << "Error: Cannot open file.\n";
		return 0;
	}
	if (file.bad())
	{
		std::cerr << "Error: Low-level I/O.\n";
		return 0;
	}

	// check read accross file(eof)
	buff << file.rdbuf();
	if (file.bad())
	{
		std::cerr << "Error: Low-level I/O.\n";
		return 0;
	}
	if (!buff)
	{
		std::cerr << "Error: File is empty.\n";
		return 0;
	}
	//loop it?
	//clear() on error to reset flag
	//seekg(0) reset position after reset flag

	// close opened file AFTER reading(eof flag set) succeed
	if (file.eof())
		file.close();

	// stock buff string into real one
	content = buff.str();
	std::cout << content << std::endl;

	//"aladdin mother fucker ![EOF]", s1 = "o", s2 = "p"
	pos = 0;
	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		result += content.substr(pos, found - pos);		//copy all BEFORE s1(start pos = [0] of s1)
		result += s2;									//add s2 at pos
		pos = found + s1.length();
	}
	result += content.substr(pos, std::string::npos);

	//write result in text.replace.txt files(stock filename to reuse it)
	std::cout << result << std::endl;
	return 0;
}
