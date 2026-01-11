# Ex01 : Try - catch inner scope
[cplusplus.com - Documentation[1]](https://cplusplus.com/doc/tutorial/exceptions/)

## New concepts
* inner try - catch blocks scope
* ..> dependency relation

## Already seen
* try - catch blocks, see [1]
* throw keyword, see [1]
* std::exception &e
* exception::what() overriding

```mermaid
classDiagram
	class Bureaucrat {
		-name : String
		-grade : unsigned int
		+incrementGrade()
		+decrementGrade()
		+signForm( Form )
		+GradeTooHighException()
		+GradeTooLowException()
	}

	class Form {
		-name : String
		-isSigned : bool
		-signedGrade : unsigned int
		-executedGrade : unsigned int
		+beSigned( Bureaucrat )
		+GradeTooHighException()
		+GradeTooLowException()
	}

	Bureaucrat ..> Form : manages
	Form ..> Bureaucrat : verified by