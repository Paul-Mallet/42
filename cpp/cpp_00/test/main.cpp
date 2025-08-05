/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:48:44 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/05 14:55:44 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Test {
	public:
		float const pi;
		Test( void );
		Test( float const a );
		Test( float const a ) : pi(a) {
			std::cout << "Constructor Init List called !" << std::endl;
			std::cout << "this->pi: " << this->pi << std::endl;
		};
		~Test( void );
		const void print( void ) const;
};

Test::Test( void ) : pi(2.56f) {
	std::cout << "Constructor called !" << std::endl;
}

Test::Test( float const a ) : pi(a) {
	std::cout << "Constructor Init List called !" << std::endl;
	std::cout << "this->pi: " << this->pi << std::endl;
}

Test::~Test( void ) {
	std::cout << "Destructor called !" << std::endl;
}

//print

int main( void )
{
	Test instance;
	Test instance_init_list(3.14f);

	std::cout << "instance.pi: " << instance.pi;
	std::cout << "instance_init_list.pi: " << instance_init_list.pi;
	return 0;
}