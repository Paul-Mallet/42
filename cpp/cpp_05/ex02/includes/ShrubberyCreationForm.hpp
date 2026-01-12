/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:38:25 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/12 15:32:08 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include <fstream>

class AForm;

/**
 * @class AForm
 * @brief Abstract Classe représentant un formulaire administratif.
 * * Un formulaire possède un nom, un statut (signé ou non) et des grades requis
 * pour la signature et l'exécution. Les grades sont immuables et doivent être
 * compris entre 1 et 150.
 */
class ShrubberyCreationForm: public AForm {

	private:
		std::string _target;

	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string const target );
		ShrubberyCreationForm( ShrubberyCreationForm const &src );
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=( ShrubberyCreationForm const &rhs );

		void	executeAction( void ) const;
};

#endif