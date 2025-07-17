/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:32:26 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/07/17 00:01:56 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

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
		virtual ~AForm();
		
		std::string get_Name() const;
		int get_Grade() const;
		int get_Grade_Sign() const;
		int get_Grade_Execute() const;

		void be_signed(const Bureaucrat &bureaucrat);
		
		friend std::ostream &operator<<(std::ostream &os, const AForm &Form);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what();
		};
	
};




#endif