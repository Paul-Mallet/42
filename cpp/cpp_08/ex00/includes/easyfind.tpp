/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:49:19 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/03 19:35:41 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include <iostream>
# include <algorithm>

/**
 * @brief Find the 1rst occurence of value in a given std::vector
 */
template<typename T>
int easyfind( T container, int value ) {
	std::vector<int>::iterator it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw (IntNotFoundException());
	return (value);
};

#endif