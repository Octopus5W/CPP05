/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:40:56 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/12/03 12:18:43 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
	Bureaucrat bureaucrat1("Alice", 1);
	Bureaucrat bureaucrat2("Bob", 12);
	
	
	try
	{
		AForm *form1 = new PresidentialPardonForm("Kakou");
		AForm *form2 = new RobotomyRequestForm("Kaka");
		AForm *form3 = new ShrubberyCreationForm("Kiki");
		
		bureaucrat1.signForm(*form1);
		bureaucrat2.signForm(*form2);
		bureaucrat2.signForm(*form3);
		
		bureaucrat1.executeForm(*form1);
		bureaucrat2.executeForm(*form2);
		bureaucrat2.executeForm(*form3);
		
		delete form1;
		delete form2;
		delete form3;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	
	return 0;
}