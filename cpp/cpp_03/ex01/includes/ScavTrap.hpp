/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:35:53 by pamallet          #+#    #+#             */
/*   Updated: 2025/12/08 22:44:55 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "./ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:
		ScavTrap( void );
		ScavTrap( std::string const &name );
		ScavTrap( ScavTrap const &src );
		~ScavTrap();

		ScavTrap &operator=( ScavTrap const &rhs );

		void 	attack(const std::string& target);
		void	guardGate();

};

#endif