/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filestream.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:43:34 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/18 10:07:24 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Filestream.hpp"

Filestream::Filestream( const std::string filename,
	const std::string s1,
	const std::string s2 ) : _filename(filename), _s1(s1), _s2(s2) {
	std::cout << "Filestream created.\n";
}

Filestream::~Filestream() {
	std::cout << "Filestream destroyed.\n";
}

const std::string Filestream::inContent( void ) {
	this->_ifs.open(this->_filename.c_str(), std::ifstream::in);
	if (!this->_ifs.is_open())
	{
		std::cerr << "Error: Ifs: Cannot open file.\n";
		return "";
	}
	if (this->_ifs.fail())
	{
		std::cerr << "Error: Ifs: Cannot open file.\n";
		return "";
	}
	if (this->_ifs.bad())
	{
		std::cerr << "Error: Ifs: Low-level I/O.\n";
		return "";
	}
	this->_buff << this->_ifs.rdbuf();
	if (this->_ifs.bad())
	{
		std::cerr << "Error: Ifs filebuf: Low-level I/O.\n";
		return "";
	}
	if (!this->_buff)
	{
		std::cerr << "Error: buff: File is empty.\n";
		return "";
	}
	if (this->_ifs.eof())
		this->_ifs.close();
	std::cout << "Content successfully read from a <filename>.\n";
	const std::string content = this->_buff.str();
	return content;
}

const std::string Filestream::replaceContent( const std::string &content ) {
	std::string				res;
	std::string::size_type	found;
	std::string::size_type	pos;

	pos = 0;
	while ((found = content.find(this->_s1, pos)) != std::string::npos)
	{
		res += content.substr(pos, found - pos);
		res += this->_s2;
		pos = found + this->_s1.length();
	}
	res += content.substr(pos, std::string::npos);
	std::cout << "Content successfully replace.\n";
	return res;
}

void Filestream::outContent( const std::string result ) {
	std::string filename;

	filename = this->_filename;
	filename.append(".replace");
	this->_ofs.open(filename.c_str(), std::ofstream::out);
	if (!this->_ofs.is_open())
	{
		std::cout << "Error: Ofs: Cannot open file.\n";
		return ;
	}
	if (this->_ofs.fail())
	{
		std::cerr << "Error: Ofs: Cannot open file.\n";
		return ;
	}
	if (this->_ofs.bad())
	{
		std::cerr << "Error: Ofs: Low-level I/O.\n";
		return ;
	}
	this->_ofs << result;
	this->_ofs.close();
	std::cout << "Content successfully write in a new <filename>.replace.\n";
}