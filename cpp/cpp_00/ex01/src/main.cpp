/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:41:36 by pamallet          #+#    #+#             */
/*   Updated: 2025/07/31 19:19:32 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

using std::cout;

class PhoneBook {
	int	width, height; //private specifier(auto scope)
	public:
		void myFunction(int, int);	//inline class member(method)
}; //[phonebook] = int [a];

// not inline class member, for possible compiler opti
void	PhoneBook::myFunction(int a, int b) {
	width = a;
	height = b;
	cout << "test2 " << width*height << "\n";
}

class Contact {
		
};

/*
<iostream>: stream() object
	std::cin -> input stream, "ADD", "SEARCH" & "EXIT", rest is ignored
	std::cout -> output...
<string>: [TODO]
	std:: [TODO]
<iomanip>: format output(phonebook's table align columns)
	std::setw(10) << '.' -> output field width strict to 10 ex: "|" << "some info." << "|"
	std::[TODO]
access specifiers = access rights for instances
	private: owner class scope,
	protected: new instance + owner class scope,
	public: accessible anywhere it is visible

program run -> 3 cmds(ADD, SEARCH, EXIT)
*/
int	main(void)
{
	PhoneBook	phonebook;
	Contact		contact;

	phonebook.myFunction(3, 4);
	return (0);
}
