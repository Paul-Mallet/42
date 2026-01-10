/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:38:25 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/10 19:28:35 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "./AForm.hpp"

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

		void	createShrubbery( void );
};

#endif