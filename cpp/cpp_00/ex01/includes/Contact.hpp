/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:53:15 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/03 19:59:40 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

using std::string;

/*
	string[5]
	ADD 1 contact, then SEARCH, ADD = seg fault(instead of index)
*/
class Contact {
	public:
		string infos[5];
		Contact() {};
		void add();
		void display();
};

#endif