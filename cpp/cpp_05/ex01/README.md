# Ex01 : Exceptions
[cplusplus.com - Documentation[1]](https://cplusplus.com/doc/tutorial/exceptions/)

## New concepts
* #pragma once, [cplusplus.com - forum](https://cplusplus.com/forum/beginner/7877/)
* ...

## Already seen
* try - catch blocks, see [1]
* throw keyword, see [1]
* std::exception &e
* virtual MyException::what() const throw() overriding

```mermaid
classDiagram
	class Bureaucrat {
		<<get>> -name : String
		<<get>> -grade : uint
		+incrementGrade()
		+decrementGrade()
		+GradeTooHighException()
		+GradeTooLowException()
	}