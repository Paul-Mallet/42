/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:53:49 by pamallet          #+#    #+#             */
/*   Updated: 2025/09/03 15:29:30 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap {

	public:
		FragTrap( void );
		FragTrap( std::string const &name );
		FragTrap( FragTrap const &src );
		~FragTrap();

		FragTrap &operator=( FragTrap const &rhs );

		void highFivesGuys( void );
};

#endif