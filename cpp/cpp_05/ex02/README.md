# Ex02 : fostream & rand()
[cplusplus.com - Exeception Documentation[1]](https://cplusplus.com/doc/tutorial/exceptions/)
[cplusplus.com - ofstream[2]](https://cplusplus.com/reference/fstream/ofstream/)
[cplusplus.com - rand()[3]](https://cplusplus.com/reference/cstdlib/rand/)

## New concepts
* std::ofstream from fstream lib, see [2]
* rand() function from cstdlib, see [3]
* <|-- inheritance relation

## Already seen
* try - catch blocks, see [1]
* throw keyword, see [1]
* std::exception &e
* * exception::what() overriding
* inner try - catch
* ..> dependency relation

```mermaid
classDiagram
	class Bureaucrat {
		-name : String
		-grade : unsigned int

		+incrementGrade()
		+decrementGrade()
		+signForm( AForm )
		+executeForm( AForm )
		+GradeTooHighException()
		+GradeTooLowException()
	}

	class AForm {
		<<Abstract>>
		-name : String
		-isSigned : bool
		-signedGrade : unsigned int
		-executedGrade : unsigned int

		+beSigned( Bureaucrat b )
		+<i>executeAction()</i> 0
		+execute( Bureaucrat executor )
		+GradeTooHighException()
		+GradeTooLowException()
		+FormNotSignedException()
	}

	class ShrubberyCreationForm {
		-target : String
		+executeAction()
	}

	class RobotomyRequestForm {
		-target : String
		+executeAction()
	}

	class PresidentialPardonForm {
		-target : String
		+executeAction()
	}

	Bureaucrat ..> AForm : manages
	AForm ..> Bureaucrat : verified by
	AForm <|-- ShrubberyCreationForm
	AForm <|-- RobotomyRequestForm
	AForm <|-- PresidentialPardonForm