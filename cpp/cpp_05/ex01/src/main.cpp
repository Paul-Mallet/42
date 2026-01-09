/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 22:43:57 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/09 11:52:13 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main( int ac, char **av ) {

	if (ac != 1)
		return (1);

	(void)av;

	Bureaucrat* john;
	Bureaucrat* priscillia;
	Form* form2;
	Form* out_form;

	try {
		Bureaucrat stagiaire;
		john = new Bureaucrat("John", 100);
		priscillia = new Bureaucrat("Priscillia", 90);
		Form form1;
		form2 = new Form("Experimentals", 150, 89);
		out_form = new Form( *form2 );
		// Form badForm("BadForm", 151, 150);
		// Form badForm2("BadForm2", 150, 151);

		std::cout << *john << std::endl;
		std::cout << *priscillia << std::endl;
		std::cout << form1 << std::endl;
		std::cout << *form2 << std::endl;
		std::cout << *out_form << std::endl;

		stagiaire.signForm( form1 );
		std::cout << form1.getIsSigned() << std::endl;
		(*john).signForm( form1 );
		std::cout << form1.getIsSigned() << std::endl;

		stagiaire.signForm( *form2 );
		std::cout << (*form2).getIsSigned() << std::endl;

		delete john;
		delete priscillia;
		delete form2;
		delete out_form;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		delete john;
		delete priscillia;
		delete form2;
		delete out_form;
	}
	return (0);
}