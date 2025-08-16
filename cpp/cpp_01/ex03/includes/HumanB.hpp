/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:57:13 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/16 12:19:59 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB {

	public:
		HumanB( std::string name );
		~HumanB();

		void setWeapon( Weapon weapon ); //need it in main.cpp

		void attack( void );

	private:
		std::string _name;
		Weapon *_weapon;

};

#endif