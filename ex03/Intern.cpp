#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &other)
{
}

Intern &Intern::operator=(const Intern &other)
{
    return *this;
}

const char* Intern::UnknownFormException::what() const throw()
{
	return "Exception : Unknown form type";
}


AForm* createPresidentialPardonForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm* createRobotomyRequestForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm* createShrubberyCreationForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string formNames[3] = {
	"presidential pardon",
	"robotomy request",
	"shrubbery creation"
    };

    AForm* formFunc[3] = {
	createPresidentialPardonForm(target),
	createRobotomyRequestForm(target),
	createShrubberyCreationForm(target)
    };

    for (int i = 0; i < 3; ++i)
    {
	if (formName == formNames[i])
	{
	    std::cout << "Intern creates " << formName << " form." << std::endl;
	    return formFunc[i];
	}
    }
    throw UnknownFormException();
    return 0;
}