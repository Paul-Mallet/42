/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:03:55 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/07 19:11:49 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main(int ac, char **av)
{
	if (ac < 1 || ac > 3)
		return (1);

	(void)av;
	Bureaucrat* eva = NULL;
	try {
		Bureaucrat god("god", 0);
		Bureaucrat ceo("ceo", 1);
		Bureaucrat philipp("philipp", 150);
		Bureaucrat me("me", 151);
		Bureaucrat bureaucrat;
		Bureaucrat bureaucrat2( bureaucrat );
		eva = new Bureaucrat("eva", 20);

		std::cout << *eva << std::endl;
		*eva = philipp;

		std::cout << bureaucrat << std::endl;
		std::cout << *eva << std::endl;
		eva->incrementGrade();
		std::cout << *eva << std::endl;
		eva->decrementGrade();
		std::cout << *eva << std::endl;
		eva->decrementGrade();
		std::cout << *eva << std::endl;

		delete eva;
	}
	catch (std::exception& e) {
		delete eva;
		std::cout << e.what() << std::endl;
	}

	return (0);
}