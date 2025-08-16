/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:10:38 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/16 11:41:36 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <new>

class Zombie {

	public:
		Zombie( void );
		Zombie( std::string name );
		~Zombie();

		void setName(std::string name);
		std::string const getName( void );

		void announce( void );

	private:
		std::string _name;
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

#endif