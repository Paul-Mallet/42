/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:12:24 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/06 14:50:24 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>

/*
	class ClassName {...};: data struct, relations with namespaces, blueprint(model) used for instances(var approach)
		ex:
			in .class.cpp
			ClassName::ClassName( void ) {...}; //dft constructor
			ClassName::~ClassName( void ) {...}; //destructor
			in main.cpp
			ClassName instance; //dft constructor runs
			instance::memberattribute; //in class attr
			instance::memberfunction(); //in class func
	producers: functions which are auto run by compiler & have no return types
		contructor: 
			default: called by the C++ compiler, even not implement
					 not take params as arguments, but MUST properly init the class(object) itself
			init list: instead of using 'this' keyword, directly get instance params
					   set in the class constructor or outside by calling ClassName::ClassName() : attr1(value1), attr2(value2) {};
				ex:
				ClassName::ClassName(int val1, string val2): attr1(val1), attr2(val2) {
					std::cout << this.attr1 << std::endl;
					std::cout << this.attr2 << std::endl;
				};
		desctrutor: MUST properly destroy the class(object) itself, if dynamic allocs were made then delete them...
	data members:
		member attributes: like vars in C, diff settable class scopes,
						   used as pointer('.') when instanciated
		member functions: C++ auto add 1rst param as a pointer to the curr object/instance(with 'this'),
						  even with void declaration, there's always 1 param at least
			ex: class ClassName {
				public:
					int attr1;
					char attr2;
					void func( void );
			}
			void ClassName::func( void ) { std::cout << "Called func !" << std::endl; };
			ClassName instance;
			instance.attr1 = 42;
			instance.attr2 = 'c';
			cout << "instance.func(): " << instance.func() << endl;
	this: pointer to current object itself(class if not instancied, or instances(individually)),
		  'this->attr1; / this->func();' to access attribute/function members,
		  this alone to refer to the object itself
		  use cases:
		  	to disambiguate(resolve ambiguity by telling compiler which var i'm referring to)
		  	chaining(ClassName&(...) { return *this };)
	const: read-only restriction if all members(attr, func) are set as const too,
		   const members MUST be initialized, even in dft constructor !
		   can set 2 const / member func, both are independant,
		   const cannot modif/call other non-static/non-const data members,
		   non-const can access both const and non-const,
		   depending on const or non-const object(instance), can have both const and non-const function member,
		   		so when instance isn't const -> use the mem_fun non-const, and if instance is const, use const mem_func otherwise
			if write mem_fun that doesn't/must not change instance of a class -> const
			const mem_fun(not return type but as member), will not allow to change this->attr1 even if attr1 is non-const,
				because the whole mem_fun is declared as a const one !
			good practice of const to debug faster !!!
		ex: const void func() const {...};
			= const member function returning a const
	visibility specifiers: members scope
		private: class scope, users can't read/modif them without getters/setters, only constructor can init and access them
		protected: [#TODO]
		public: class/global scope, accessible from everywhere, by everyone
		class vs struct: private by dft vs public by dft
	accessors: proxy mem_func between users and private members of the class
		getters: const way, only read this->attr from private visibility of the class
		setters: following set of conditions, after all passes, set this->attr based on given param
	comparisons: == allowed to make addresses comparisons
		physical: &instance1 != &instance2
		structural: instance1.compare( &instance2 ) == 0
	static(non-members, class attr/func): allowed to have same attribute value accross several instances of its defined class,
									  	  when set, will NOT auto pass 'this' as a param of a non-mem func !
										  to init values of those, do it outside Class::functions or constructor/destructor
										  just like basic Class::function() {}; syntax, type Class::attribute = value;
	pointer to members: 3 steps to use them(same way as C),
						useful for a collection of instances(array, vector, list, map, set...) !!!
						(DRY Principle: instead of writing 1 func/member, write 1 func/generical feature and recall it)
		1. declare pointers for instances 1rst, then members(attr, func) too
		2. init member's pointers by given them addresses of current Class members
		3. by dereferencing those pointers, given them the value needed or calling them(if function without params)
		ex:
		Class ClassName {
			public:
				ClassName ( void );
				~ClassName ( void );

				void bar( int a ) const;

			private:
				int _foo;
		};

		ClassName::bar( int a ) {
			std::cout << a << std::endl;
		};

		ClassName instance;
		ClassName *instancep = &instance;

		int 	ClassName::*p = NULL;

		p = &ClassName::_foo;
		instance.*p = 21;
		instancep->*p = 42;

		void	(ClassName::*f)( int a ) const;

		f = &ClassName::_bar;
		(instance.*f)(21);
		(instancep->*f)(42);
	'::': scope operator
*/
class Contact {

	public:
		Contact( void );
		~Contact( void );

		std::string getFirstname( void ) const;
		std::string getLastname( void ) const;
		std::string getNickname( void ) const;
		std::string getPhonenum( void ) const;
		std::string getDarksecret( void ) const;

		void setFirstname( std::string str );
		void setLastname( std::string str );
		void setNickname( std::string str );
		void setPhonenum( std::string str );
		void setDarksecret( std::string str );

		void addContact( void );
		void displayContactField( std::string Contact::*fieldPtr ) const;
		void displayContactStatus( void ) const;
		void displayContactInfos( void ) const;

	private:
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _phonenumber;
		std::string _darksecret;
};

#endif