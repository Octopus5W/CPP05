/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:40:56 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/11/30 12:39:50 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main ()
{
	try
	{
		Bureaucrat bureaucrat1("Alice", 140);
		Bureaucrat bureaucrat2("Bob", 12);
		
		Form form1("Form A", 149, 50);
		Form form2("Form B", 25, 10);
		
		std::cout << bureaucrat1;
		std::cout << form1;
		bureaucrat1.signForm(form1);
		std::cout << form1;
		std::cout << "---------------------" << std::endl << std::endl;
		std::cout << bureaucrat2;
		std::cout << form2;
		bureaucrat2.signForm(form2);
		std::cout << form2;
		std::cout << "---------------------" << std::endl << std::endl;
		std::cout << bureaucrat2;
		std::cout << form2;
		bureaucrat2.signForm(form2);
		std::cout << form2;
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
}