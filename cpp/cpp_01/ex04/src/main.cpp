/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 09:44:50 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/17 20:15:32 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Filestream.hpp"
/*
	std::ifstream: input file stream
		open(filename(as const char *), std::ifstream::in)
		ifs.is_open() -> bool check if opening succeed
		ifs.rdbuf() -> get/set ptr to stream buff curr associated to the stream BEFORE the call
		stream buffer Object -> 
		clear() -> reset state flag / error
		seekg(0, [std::ios::beg]) -> reset read pos at file's [beginning](optionnal)
	std::ofstream: output file stream
		open(filename(as const char *), std::ofstream::out)
		same as ifstream
	std::iostream::mode
		in -> open for reading in internal stream buff
		out -> open for writing in internal stream buff
		binary -> bin mode rather than string
		ate -> at end, output pos that starts at end of file(eof)
		app -> append output operations append at eof of it
		trunc -> truncate any contents that existed before opening the file are discarded(erase) after openedd it
	states(flags):
		good() -> goodbit: no error state
		eof() -> eofbit: while performing an extracting operation(CTRL+C/D...) on stream
		fail() -> failbit: input logical, parsing error
		bad() -> badbit: irrecoverable error(Disk errors(full during write), Network issues(co drops), Permission changes(file perms revokes while stream is open), Device removal(USB drive unplugged)...)
	std::string:
		substr(pos, len) -> return new Object sub string based on start pos and spans len characters/until end of string
		find(str_occurence, pos) -> return 1rst char of 1rst occurence if found at start pos given in 2nd param
		std::string::npos -> max constant value for size_t = -1, used as a value for a len = until end of the string
*/
// Using C file manipulation functions is forbidden and will be considered cheating !!! ask AI
// You must create and turn in your own test !!!

int main( int ac, char **av )
{
	std::string filename;
	std::string s1;
	std::string s2;

	if (ac != 4)
	{
		std::cout << "Format required: ./streamfile <filename> s1 s2\n";
		return 0;
	}

	filename = av[1];
	s1 = av[2];
	s2 = av[3];
	Filestream file(filename, s1, s2);

	const std::string content = file.inContent();
	if (content.empty())
		return 0;
	const std::string result = file.replaceContent(content);
	file.outContent(result);
	return 0;
}

// int main( int ac, char **av )
// {
// 	std::ifstream ifs;
// 	std::string filename;
// 	std::string s1;
// 	std::string s2;
// 	std::stringstream buff;
// 	std::string content;
// 	std::string result;
// 	std::string::size_type found;
// 	std::string::size_type pos;

// 	// check input basic formats
// 	if (ac != 4)
// 	{
// 		std::cout << "Format required: ./streamfile <filename> s1 s2\n";
// 		return 0;
// 	}

// 	//stock in vars for better readability
// 	filename = av[1];
// 	s1 = av[2];
// 	s2 = av[3];

// 	// -------------- .getContent() ----------------

// 	// check stream state after opened file
// 	ifs.open(filename.c_str(), std::ifstream::in);
// 	if (!ifs.is_open())
// 	{
// 		std::cerr << "Error: Ifs: Cannot open file.\n";
// 		return 0;
// 	}
// 	if (ifs.fail())
// 	{
// 		std::cerr << "Error: Ifs: Cannot open file.\n";
// 		return 0;
// 	}
// 	if (ifs.bad())
// 	{
// 		std::cerr << "Error: Ifs: Low-level I/O.\n";
// 		return 0;
// 	}

// 	// check read accross file(eof)
// 	buff << ifs.rdbuf();
// 	if (ifs.bad())
// 	{
// 		std::cerr << "Error: Ifs filebuf: Low-level I/O.\n";
// 		return 0;
// 	}
// 	if (!buff)
// 	{
// 		std::cerr << "Error: buff: File is empty.\n";
// 		return 0;
// 	}

// 	// close opened file AFTER reading(eof flag set) succeed
// 	// ifs error state loop based on
// 	if (ifs.eof())
// 		ifs.close();

// 	// stock buff string into real one
// 	content = buff.str();

// 	// -------------- .replaceContent() ----------------

// 	// loop over content to replace each occurences if found | pos, found, result
// 	pos = 0;
// 	while ((found = content.find(s1, pos)) != std::string::npos)
// 	{
// 		result += content.substr(pos, found - pos);
// 		result += s2;
// 		pos = found + s1.length();
// 	}
// 	result += content.substr(pos, std::string::npos);

// 	// -------------- .outContent() ----------------

// 	// open/create another file to output result within it
// 	filename.append(".replace");
// 	std::ofstream ofs(filename.c_str(), std::ofstream::out);
// 	if (ofs.fail())
// 	{
// 		std::cout << "Error: Ofs: Cannot open file.\n";
// 		return 0;
// 	}
// 	if (ofs.fail())
// 	{
// 		std::cerr << "Error: Ofs: Cannot open file.\n";
// 		return 0;
// 	}
// 	if (ofs.bad())
// 	{
// 		std::cerr << "Error: Ofs: Low-level I/O.\n";
// 		return 0;
// 	}

// 	// close currently open file stream
// 	ofs << result;
// 	ofs.close();
// 	return 0;
// }
