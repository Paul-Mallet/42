/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:19:39 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/29 10:48:51 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <exception>

/**
 * @brief Base class, that generate random types and then identify them (typeinfo)
 * It doesn't have to be designed in Orthodox Canonical Form
*/
class Base {

	public:
		virtual ~Base();

		static Base*	generate ( void );
		static void		identify (Base* p);
		static void		identify (Base& p);

};

#endif