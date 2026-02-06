/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:21:06 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/06 10:12:23 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack: public std::stack<T> {

	public:
		MutantStack( void ): std::stack<T>() {};
		MutantStack( MutantStack const & src ): std::stack<T>(src) {};
		~MutantStack() {};

		MutantStack & operator=( MutantStack const & rhs ) {
			if (this != &rhs)
				std::stack<T>::operator=(rhs);
			return (*this);
		};

		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator				begin() { return (this->c.begin()); };
		iterator				end() { return (this->c.end()); };
		const_iterator			cbegin() const { return (this->c.cbegin()); };
		const_iterator			cend() const { return (this->c.cend()); };
		reverse_iterator 		rbegin() { return (this->c.rbegin()); };
		reverse_iterator 		rend() { return (this->c.rend()); };
		const_reverse_iterator	crbegin() const { return (this->c.crbegin()); };
		const_reverse_iterator	crend() const { return (this->c.crend()); };

};

#endif