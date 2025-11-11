/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:40:56 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/11/11 13:40:27 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main ()
{
	Bureaucrat bureaucrat1("Alice", 100);
	Bureaucrat bureaucrat2("Bob", 12);
	
	Form form1("Form A", 75, 50);
	Form form2("Form B", 25, 10);
	
	
	try
	{
		std::cout << bureaucrat1;
		std::cout << form1;
		form1.be_signed(bureaucrat1);
		std::cout << form1;
		
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << bureaucrat2;
		std::cout << form2;
		form2.be_signed(bureaucrat2);
		std::cout << form2;
		
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	
	return 0;
}