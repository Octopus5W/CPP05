/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:32:26 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/11/11 13:53:28 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const int grade_sign;
		const int grade_execute;
	public:
		Form(std::string name, int grade_sign, int grade_execute);
		~Form();
		Form(const Form &other);
		Form &operator=(const Form &other);
		
		std::string get_Name() const;
		int get_Grade() const;
		int get_Grade_Sign() const;
		int get_Grade_Execute() const;
		bool get_Is_Signed() const;
		
		void be_signed(const Bureaucrat &bureaucrat);
		
		friend std::ostream &operator<<(std::ostream &os, const Form &Form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	
};




#endif