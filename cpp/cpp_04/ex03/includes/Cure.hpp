/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:10:13 by pamallet          #+#    #+#             */
/*   Updated: 2025/09/01 16:13:40 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {
public:
    Cure( void );
    Cure( std::string const &type );
    Cure( Cure const &src );
    ~Cure();

    Cure &operator=(Cure const &rhs);

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif