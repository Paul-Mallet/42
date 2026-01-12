/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 11:45:54 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/12 15:30:35 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class AForm;

class PresidentialPardonForm: public AForm {

	private:
		std::string		_target;

	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm const &src );
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=( PresidentialPardonForm const &rhs );

		void	executeAction( void ) const;
};

#endif