/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:38:25 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/12 15:30:46 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cstdlib>

class AForm;

/**
 * @class RobotomyRequestForm
 * ...
 */
class RobotomyRequestForm: public AForm {

	private:
		std::string _target;

	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string const target );
		RobotomyRequestForm( RobotomyRequestForm const &src );
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=( RobotomyRequestForm const &rhs );

		void	executeAction( void ) const;

};

#endif