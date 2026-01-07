# Ex00 : Exceptions
[cplusplus.com - Documentation[1]](https://cplusplus.com/doc/tutorial/exceptions/)

## New concepts
* #pragma once, [cplusplus.com - forum](https://cplusplus.com/forum/beginner/7877/)
* try - catch blocks, see [1]
* throw keyword, see [1]
* std::exception &e
* virtual MyException::what() const throw() overriding

## Already seen
* Fields
* Private visibility
* Getter / Setter
* Methods

```mermaid
classDiagram
	class Bureaucrat {
		<<get>> -name : String
		<<get>> -grade : uint
		+incrementGrade()
		+decrementGrade()
	}
```mermaid