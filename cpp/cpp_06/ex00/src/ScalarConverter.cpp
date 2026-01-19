/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 10:49:38 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/19 18:27:31 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {
	std::cout << "Default Constructor - ScalarConverter" << std::endl;
}

ScalarConverter::ScalarConverter( ScalarConverter const &src ) {
	std::cout << "Copy constructor - ScalarConverter" << std::endl;
	(void)src;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor - ScalarConverter" << std::endl;
}

ScalarConverter &ScalarConverter::operator=( ScalarConverter const &rhs ) {
	std::cout << "Copy Assignment Operator - ScalarConverter" << std::endl;
	(void)rhs;
	return (*this);
}

// is it psdliteral?
// if yes, what do we do? display, compute???
static bool ispsdliteral( std::string literal ) {
	int					idx = -1;
	const std::string	psd_literals[MAX_PSD_LITERALS] = { "nan", "nanf", "+inf", "+inff", "-inf", "-inff" };
	enum 				{ NAN, PINF, MINF};

	for (size_t i = 0; i < MAX_PSD_LITERALS; i++) {
		if (literal == psd_literals[i]) {
			idx = (int)i / 2;
			break ;
		}
	}
	if (idx != -1) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	switch (idx) {
		case NAN:
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			return (true);
		case PINF:
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
			return (true);
		case MINF:
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
			return (true);
		default:
			return (false);
	}
}

static void impossible( void ) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static void displayInt( std::string literal ) {
	// isDoubleOverflow()
	long double val = strtold(literal.c_str(), NULL);

	if (val < -std::numeric_limits<double>::max() || val > std::numeric_limits<double>::max())
		return impossible();

	int i = val;
	// isCharOverflow()
	if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (i < 32 || i > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	// isIntOverflow()
	if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	// isFloatOverflow()
	if (val < -std::numeric_limits<float>::max() || val > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << 'f' << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << std::endl;
}

static void displayChar(std::string literal, int idx, bool displayable) {
	if (!displayable) {
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(literal[idx]) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(literal[idx])  << 'f' << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(literal[idx]) << std::endl;
	} else {
		std::cout << "char: " << static_cast<char>(literal[idx]) << std::endl;
		std::cout << "int: " << static_cast<int>(literal[idx]) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(literal[idx])  << 'f' << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(literal[idx]) << std::endl;
	}
}

static void displayFloat( std::string literal ) {
	long double val = strtold(literal.c_str(), NULL);

	if (val < -std::numeric_limits<double>::max() || val > std::numeric_limits<double>::max())
		return impossible();

	float f = val;
	if (f < 0 || f > 127)
		std::cout << "char: impossible" << std::endl;
	else if (f < 32 || f > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(f) << std::endl;

	if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;

	if (f < -std::numeric_limits<float>::max() || f > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << 'f' << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << std::endl;
}

static void displayDouble( std::string literal ) {
	long double val = strtold(literal.c_str(), NULL);

	if (val < -std::numeric_limits<double>::max() || val > std::numeric_limits<double>::max())
		return impossible();

	double	d = val;
	if (d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if (d < 32 || d > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(d) << std::endl;

	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << 'f' << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convert( std::string literal ) {
	int idx = 0;

	if (ispsdliteral(literal))
		return ; // todo

	if ((literal[idx] == '0' && literal[idx + 1] != '.' && literal.length() > 1)
		|| (literal[idx] == '-' && literal[idx + 1] == '0' && literal[idx + 2] != '.' && literal.length() > 2)
		|| literal.length() == 0) {
			return impossible();
		}

	if (literal[idx] == '-')
		idx++;

	while (isdigit(literal[idx]))
		idx++;
	if ((size_t)idx == literal.length())
		return displayInt(literal); // todo

	if (!isprint(literal[idx]) && literal.length() == 1)
		return displayChar(literal, idx, false);
	if (isprint(literal[idx]) && literal.length() == 1)
		return displayChar(literal, idx, true);

	if (literal[idx] == '.')
		idx++;
	while (isdigit(literal[idx]))
		idx++;
	if ((size_t)idx == literal.length())
		return displayDouble(literal);

	if (literal[idx] == 'f' && (literal.find('.') != (size_t)(-1)))
		idx++;
	if ((size_t)idx == literal.length())
		return displayFloat(literal);
	return impossible();
}