/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:32:26 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/11/30 12:38:22 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string name;
		bool is_signed;
		const int grade_sign;
		const int grade_execute;
	public:
		AForm(std::string name, int grade_sign, int grade_execute);
		virtual ~AForm();
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		
		std::string get_Name() const;
		int get_Grade() const;
		int get_Grade_Sign() const;
		int get_Grade_Execute() const;
		bool get_Is_Signed() const;
		
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;
		friend std::ostream &operator<<(std::ostream &os, const AForm &AForm);

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

		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	
};




#endif