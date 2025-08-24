/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 09:21:06 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/24 11:21:31 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "./ClapTrap.hpp"
# include "./ScavTrap.hpp"
# include "./FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

	public:
		DiamondTrap( void );
		DiamondTrap( std::string const &name );
		DiamondTrap( DiamondTrap const &src );
		~DiamondTrap();

		DiamondTrap &operator=( DiamondTrap const &rhs );

		void 	attack( const std::string& target );
		void 	whoAmI( void );

	private:
		std::string 	_name;

};

#endif