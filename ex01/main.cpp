/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:40:56 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/07/16 21:25:01 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main ()
{
	Bureaucrat bureaucrat1("Alice");
	Bureaucrat bureaucrat2("Bob");
	Bureaucrat bureaucrat3("Annique");
	
	std::cout << bureaucrat1;
	std::cout << bureaucrat2;
	std::cout << bureaucrat3;

	try
	{
		bureaucrat1.increment_Grade();
		std::cout << bureaucrat1.get_Name() << " after increment has grade " << bureaucrat1.get_Grade() << std::endl;
		bureaucrat2.decrement_Grade();
		std::cout << bureaucrat2.get_Name() << " after decrement has grade " << bureaucrat2.get_Grade() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}