# Ex00 : Exceptions
[cplusplus.com - Documentation[1]](https://cplusplus.com/doc/tutorial/exceptions/)

## New concepts
* #pragma once, [cplusplus.com - forum](https://cplusplus.com/forum/beginner/7877/)
* try - catch blocks, see [1]
* throw keyword, see [1]

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