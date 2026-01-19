/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:05:01 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/19 11:48:53 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
// #include <typeinfo>

int	main( int ac, char **av )
{
	if (ac != 1)
		return (1);
	(void)av;

	Base* pbb = new Base;
	Base* pa = new A;
	Base* pb = new B;
	Base* pc = new C;
	Base* pr;
	Base* pr2;
	time_t	rawtime;

	std::cout << std::time(&rawtime) << std::endl;
	std::srand(std::time(&rawtime));

	pr = Base::generate();
	pr2 = Base::generate();

	std::cout << std::endl;

	Base::identify(pr);
	Base::identify(pr2);
	Base::identify(pbb);
	Base::identify(pa);
	Base::identify(pb);
	Base::identify(pc);

	std::cout << std::endl;

	std::cout << &pr << std::endl;
	std::cout << &pr2 << std::endl;
	std::cout << &pbb << std::endl;
	std::cout << &pa << std::endl;
	std::cout << &pb << std::endl;
	std::cout << &pc << std::endl;

	std::cout << std::endl;

	Base::identify(*pr);
	Base::identify(*pr2);
	Base::identify(*pbb);
	Base::identify(*pa);
	Base::identify(*pb);
	Base::identify(*pc);

	std::cout << std::endl;

	// std::cout << typeid(pr).name() << std::endl;
	// std::cout << typeid(pr2).name() << std::endl;
	// std::cout << typeid(pbb).name() << std::endl;
	// std::cout << typeid(pa).name() << std::endl;
	// std::cout << typeid(pb).name() << std::endl;
	// std::cout << typeid(pc).name() << std::endl;

	// std::cout << std::endl;

	delete pr;
	delete pr2;
	delete pbb;
	delete pa;
	delete pb;
	delete pc;
	return (0);
}