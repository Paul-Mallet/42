/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:25:09 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/07 15:20:27 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
	std::ref (references):
		1. in C pointers allow to access variable out of a scope,
		some kind of 'alias' for ALREADY existing var
		= const ptr always unreferenced, never void
		obligate to ref to a value already init? != int *ptr; //point to nothing yet
		= derefenrenced ptr

		2. passing params as ref, just like ptrs, but already deref
		func(std::string const &str) {str}

		3. using within a class
		class ClassName {
			private:
				...
			public:
				Student(std::string const &login) : _login(login) {}; //as init list constructor
				//destructor
				std::string const &getLoginRefConst() { return this->_login; }
				// (main.cpp) => instance.getLoginRefConst();
				std::string const *getLoginPtrConst() { return &(this->_login); }
				// (main.cpp) => *(instance.getLoginPtrConst());
			};

		IMPORTANT: don't replace pointers ! just complement them !
				   using a ptr to something that doesn't exist from the beginning(at init, constructor)

		TIPS:
			ptr => if at some point it(the var ptr/ref by) should not always exist
			ref => should always exist(init) and never change
*/
int main( void ) {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = *stringPTR;

	std::cout << "string mem: " << &string << std::endl;
	std::cout << "stringPTR mem: " << stringPTR << std::endl;
	std::cout << "stringREF mem: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "string value: " << string << std::endl;
	std::cout << "stringPTR value: " << *stringPTR << std::endl;
	std::cout << "stringREF value: " << stringREF << std::endl;

	return 0;
}
