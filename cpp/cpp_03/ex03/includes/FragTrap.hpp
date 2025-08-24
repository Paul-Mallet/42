/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:53:49 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/24 21:45:35 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap : public virtual ClapTrap {

	public:
		FragTrap( void );
		FragTrap( std::string const &name );
		FragTrap( FragTrap const &src );
		~FragTrap();

		FragTrap &operator=( FragTrap const &rhs );

		void highFivesGuys( void );
};

#endif