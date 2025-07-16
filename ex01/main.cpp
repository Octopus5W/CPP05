/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:40:56 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/07/16 22:38:02 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main ()
{
	Bureaucrat bureaucrat1("Alice", 100);
	Bureaucrat bureaucrat2("Bob", 50);
	
	Form form1("Form A", 75, 50);
	Form form2("Form B", 25, 10);
	
	std::cout << bureaucrat1;
	std::cout << bureaucrat2;
	std::cout << form1;
	std::cout << form2;

	try
	{
		form1.be_signed(bureaucrat1);
		std::cout << bureaucrat1.get_Name() << " signed " << form1.get_Name() << std::endl;
		std::cout << form1;
		
		form2.be_signed(bureaucrat2);
		std::cout << bureaucrat2.get_Name() << " signed " << form2.get_Name() << std::endl;
		std::cout << form2;
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	return 0;
}