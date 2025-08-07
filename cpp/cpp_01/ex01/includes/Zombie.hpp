/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:18:48 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/07 12:15:31 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <new>

# define ZOMBIE_NB 3

class Zombie {

	public:
		Zombie( void );
		~Zombie( void );

		void setName( std::string name );
		void announce( void );

	private:
		std::string _name;

};

Zombie *zombieHorde(int N, std::string name);

#endif