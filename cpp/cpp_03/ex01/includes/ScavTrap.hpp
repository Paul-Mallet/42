/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:35:53 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/22 16:36:26 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "./ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	
	public:
		ScavTrap( std::string const &name );
		~ScavTrap();

		void 	attack(const std::string& target);

		void	guardGate();

};

#endif