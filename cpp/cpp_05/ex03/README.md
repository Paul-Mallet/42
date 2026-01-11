# Ex03 : Single-responsibility Principle
[cplusplus.com - Exeception Documentation[1]](https://cplusplus.com/doc/tutorial/exceptions/)

## New concepts
* Single-responsibility principle, [SOLID](https://www.splunk.com/en_us/blog/learn/solid-design-principle.html)

## Already seen
* try - catch blocks, see [1]
* throw keyword, see [1]
* std::exception &e
* * exception::what() overriding
* inner try - catch
* ..> dependency relation
* std::ofstream from fstream lib, see [2]
* rand() function from cstdlib, see [3]
* <|-- inheritance relation
* switch - case - break - default

```mermaid
classDiagram
	class Bureaucrat {
		-name : String
		-grade : unsigned int

		+incrementGrade() void
		+decrementGrade() void
		+signForm( AForm ) void
		+executeForm( AForm ) void
		+GradeTooHighException() char*
		+GradeTooLowException() char*
	}

	class Intern {
        +makeForm(String name, String target) AForm*
    }

	class AForm {
		<<Abstract>>
		-name : String
		-isSigned : bool
		-signedGrade : unsigned int
		-executedGrade : unsigned int

		+beSigned( Bureaucrat b ) void
		+<i>executeAction()</i> 0
		+execute( Bureaucrat executor ) void
		+GradeTooHighException() char*
		+GradeTooLowException() char*
		+FormNotSignedException() void
	}

	class ShrubberyCreationForm {
		-target : String
		+executeAction() void
	}

	class RobotomyRequestForm {
		-target : String
		+executeAction() void
	}

	class PresidentialPardonForm {
		-target : String
		+executeAction() void
	}

	Bureaucrat ..> AForm : manages
	Intern ..> AForm : creates
	AForm ..> Bureaucrat : verified by
	AForm <|-- ShrubberyCreationForm
	AForm <|-- RobotomyRequestForm
	AForm <|-- PresidentialPardonForm