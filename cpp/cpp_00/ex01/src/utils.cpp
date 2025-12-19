/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:24:40 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/19 19:09:59 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <string>

bool isalphastr( std::string str ) {
	for (size_t i = 0; i < str.length(); ++i)
		if (!isalpha(str[i]))
			return 0;
	return 1;
};

bool isdigitstr( std::string str ) {
	for (size_t i = 0; i < str.length(); ++i)
		if (!isdigit(str[i]))
			return 0;
	return 1;
};
