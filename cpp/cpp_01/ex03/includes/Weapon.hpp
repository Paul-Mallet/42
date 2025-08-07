/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:55:01 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/07 19:01:28 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {

	public:
		Weapon( void );
		~Weapon( void );

		const std::string &getType( void );
		void setType(std::string newType);

	private:
		std::string _type;

};

#endif