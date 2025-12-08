/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:58:41 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/08 23:06:34 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {

	public:
		ClapTrap( void );
		ClapTrap( std::string const &name );
		ClapTrap( ClapTrap const &src );
		virtual ~ClapTrap();

		ClapTrap 		&operator=( ClapTrap const &rhs );

		std::string		getName( void ) const;
		unsigned int	getHitPoint( void ) const;
		unsigned int	getEnergyPoint( void ) const;
		unsigned int	getAttackDamage( void ) const;

		virtual void 	attack(const std::string& target);
		void 			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);

	protected:
		std::string 	_name;
		unsigned int	_hp;
		unsigned int	_ep;
		unsigned int	_ad;
		unsigned int	_hp_max;
		unsigned int	_ep_max;
};

std::ostream &operator<<( std::ostream &o, ClapTrap const &i );

#endif
