/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:10:13 by pamallet          #+#    #+#             */
/*   Updated: 2025/09/01 17:56:13 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {

    public:
        Ice( void );
        Ice( std::string const &type );
        Ice( Ice const &src );
        ~Ice();

        Ice &operator=(Ice const &rhs);

        AMateria* clone() const;
        void use(ICharacter& target);

};

#endif