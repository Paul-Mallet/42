/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:38:25 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/11 11:52:30 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include "./AForm.hpp"

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