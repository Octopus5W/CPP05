/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    RobotomyRequestForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:33:00 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/07/16 21:19:24 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string  RobotomyRequestForm::get_Name() const
{
    return name;
}

int  RobotomyRequestForm::get_Grade_Sign() const
{
    return grade_sign;
}

int  RobotomyRequestForm::get_Grade_Execute() const
{
    return grade_execute;
}

const char*  RobotomyRequestForm::GradeTooHighException::what()
{
    return "Exception : Grade too high";
}

const char*  RobotomyRequestForm::GradeTooLowException::what()
{
    return "Exception : Grade too low";
}

std::ostream &operator<<(std::ostream &os, const  RobotomyRequestForm & RobotomyRequestForm)
{
    os <<  RobotomyRequestForm.get_Name() << ",  RobotomyRequestForm grade to execute " 
    <<  RobotomyRequestForm.get_Grade_Execute() << ",  RobotomyRequestForm grade to sign " 
    <<  RobotomyRequestForm.get_Grade_Sign() 
    << ( RobotomyRequestForm.get_Grade_Sign() == 1 ?  ". Signed" : ". Not Signed") 
    << std::endl;
    return os;
}

void  RobotomyRequestForm::be_signed(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.get_Grade() > grade_sign)
        throw GradeTooLowException();
    std::cout << bureaucrat.get_Name() << " signs " << name << std::endl;
    is_signed = true;
}



