/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:49:19 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/03 14:09:49 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include <iostream>
# include <algorithm>

/**
 * @brief Find the 1rst occurence of value in a given Vector
 */
template<typename T>
std::vector<int>::iterator easyfind( T container, int value ) {
	std::vector<int>::iterator it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw (IntNotFoundException());
	return (it);
};

#endif