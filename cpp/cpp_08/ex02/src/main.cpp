/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:31:53 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/06 10:23:23 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <string>
#include <list>
#include <typeinfo>

template<typename T>
static void display_container( T it, T ite ) {
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}

int main( void ) {
	// ===== MutantStack tests 1 =====
	std::cout << "===== Member function from underlying container <dequeue> tests =====" << std::endl;
	MutantStack<int> mstack;
	std::cout << "mstack.push(5)" << std::endl;
	mstack.push(5);
	std::cout << "mstack.push(17)" << std::endl;
	mstack.push(17);

	std::cout << "\nmstack.top(): " << mstack.top() << std::endl;
	std::cout << "\nmstack.pop()\n" << std::endl;
	mstack.pop();
	std::cout << "mstack.size(): " << mstack.size() << "\n" << std::endl;

	std::cout << "mstack.push(5)" << std::endl;
	mstack.push(3);
	std::cout << "mstack.push(5)" << std::endl;
	mstack.push(5);
	std::cout << "mstack.push(737)" << std::endl;
	mstack.push(737);
	std::cout << "mstack.push(0)" << std::endl;
	mstack.push(0);

	if (mstack.empty())
		std::cout << "mstack is empty" << std::endl;

	// ===== MutantStack Iterators tests =====
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "++it" << std::endl;
	++it;
	std::cout << "--it" << std::endl;
	--it;
	display_container(it, ite);

	// ===== MutantStack tests 2 =====
	std::cout << "\n===== Copy constructor between 2 MutantStacks tests =====" << std::endl;
	MutantStack<int> mstack2(mstack);
	std::cout << "mstack2.size(): " << mstack2.size() << std::endl;

	MutantStack<int>::reverse_iterator cit2 = mstack2.rbegin();
	MutantStack<int>::reverse_iterator cite2 = mstack2.rend();
	display_container(cit2, cite2);

	// ===== MutantStack tests 3 =====
	std::cout << "\n===== Copy assignment between 2 MutantStacks tests =====" << std::endl;
	MutantStack<int> mstack3;
	std::cout << "mstack3.size(): " << mstack3.size() << std::endl;

	mstack3 = mstack2;
	std::cout << "mstack3.size(): " << mstack3.size() << std::endl;

	MutantStack<int>::iterator it3 = mstack3.begin();
	MutantStack<int>::iterator ite3 = mstack3.end();
	display_container(it3, ite3);

	// ===== Base std::stack tests =====
	std::cout << "\n===== Base std::stack copy constructor tests =====" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "s.size(): " << s.size() << std::endl;


	// ===== An other Base std::list tests =====
	std::cout << "\n===== Base std::list tests =====" << std::endl;
	std::list<std::string> list;
	std::cout << "list.push_back(\"pamallet\")" << std::endl;
	list.push_back("pamallet");
	std::cout << "list.push_back(\"pseudo_random\")" << std::endl;
	list.push_back("pseudo_random");

	std::cout << "\nlist.front(): " << list.front() << std::endl;
	std::cout << "\nlist.pop_front()\n" << std::endl;
	list.pop_front();
	std::cout << "list.size(): " << list.size() << "\n" << std::endl;

	std::cout << "list.push_back(\"another\")" << std::endl;
	list.push_back("another");
	std::cout << "list.push_back(\"current\")" << std::endl;
	list.push_back("current");
	std::cout << "list.push_back(\"sentence\")" << std::endl;
	list.push_back("sentence");
	std::cout << "list.push_back(\"to add\")" << std::endl;
	list.push_back("to add");

	if (list.empty())
		std::cout << "list is empty" << std::endl;

	// ===== Base std::list Iterators tests =====
	std::list<std::string>::iterator itl = list.begin();
	std::list<std::string>::iterator itel = list.end();
	std::cout << "++itl" << std::endl;
	++itl;
	std::cout << "--itl" << std::endl;
	--itl;
	display_container(itl, itel);

	return (0);
}