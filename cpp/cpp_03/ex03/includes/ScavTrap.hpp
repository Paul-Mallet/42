/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:35:53 by pamallet          #+#    #+#             */
/*   Updated: 2025/09/03 15:29:37 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "./ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

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