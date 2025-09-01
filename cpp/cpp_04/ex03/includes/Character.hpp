/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:44:32 by pamallet          #+#    #+#             */
/*   Updated: 2025/09/01 18:53:24 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "./AMateria.hpp"
# include "./ICharacter.hpp"

class Character : public ICharacter {

	private:
		std::string	 _name;
		AMateria 	*_slot[4];
		
	public:
		Character( void );
		Character( std::string const &name );
		Character( Character const &src ); //deep copy, deleted prev
		~Character();

		Character &operator=( Character const &rhs ); // deep copy, deleted prev

		std::string const &getName( void ) const;

		void equip( AMateria *m );
		void unequip( int idx );
		void use( int idx, ICharacter &target );

		void clearInventory( void );
		void copyInventory( Character const &src );

};

#endif