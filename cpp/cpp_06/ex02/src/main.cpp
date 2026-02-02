/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:05:01 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/02 17:58:08 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
// #include <typeinfo>

int	main( int ac, char **av )
{
	if (ac != 1) {
		std::cout << "Invalid arguments\nex: ./convert" << std::endl;
		return (1);
	}
	(void)av;

	Base* pbb = new Base;
	Base* pa = new A;
	Base* pb = new B;
	Base* pc = new C;
	Base* pr;
	Base* pr2;
	time_t	rawtime;

	std::cout << "===== Get current time to generate random seed =====" << std::endl;
	std::cout << std::time(&rawtime) << std::endl;
	std::srand(std::time(&rawtime));
	std::cout << std::endl;

	/**
	 * @brief Randomizer between A, B, and C
	 */
	std::cout << "===== Randomizer between A, B, and C =====" << std::endl;
	pr = Base::generate();
	pr2 = Base::generate();
	std::cout << pr << std::endl;
	std::cout << pr2 << std::endl;
	std::cout << std::endl;

	/**
	 * @brief Identify pointers
	 */
	std::cout << "===== Identify Pointers =====" << std::endl;
	Base::identify(pbb);
	Base::identify(pa);
	Base::identify(pb);
	Base::identify(pc);
	Base::identify(pr);
	Base::identify(pr2);
	std::cout << std::endl;

	/**
	 * @brief Identify references
	 */
	std::cout << &pbb << std::endl;
	std::cout << &pa << std::endl;
	std::cout << &pb << std::endl;
	std::cout << &pc << std::endl;
	std::cout << &pr << std::endl;
	std::cout << &pr2 << std::endl;
	std::cout << std::endl;

	/**
	 * @brief References tests
	 */
	std::cout << "===== Identify References =====" << std::endl;
	Base::identify(*pbb);
	Base::identify(*pa);
	Base::identify(*pb);
	Base::identify(*pc);
	Base::identify(*pr);
	Base::identify(*pr2);

	std::cout << std::endl;

	delete pbb;
	delete pa;
	delete pb;
	delete pc;
	delete pr;
	delete pr2;
	return (0);
}