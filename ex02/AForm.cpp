/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:33:00 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/07/16 21:19:24 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

 AForm::~AForm()
{
}

std::string  AForm::get_Name() const
{
    return name;
}

int  AForm::get_Grade_Sign() const
{
    return grade_sign;
}

int  AForm::get_Grade_Execute() const
{
    return grade_execute;
}

const char*  AForm::GradeTooHighException::what()
{
    return "Exception : Grade too high";
}

const char*  AForm::GradeTooLowException::what()
{
    return "Exception : Grade too low";
}

std::ostream &operator<<(std::ostream &os, const  AForm & AForm)
{
    os <<  AForm.get_Name() << ",  AForm grade to execute " 
    <<  AForm.get_Grade_Execute() << ",  AForm grade to sign " 
    <<  AForm.get_Grade_Sign() 
    << ( AForm.get_Grade_Sign() == 1 ?  ". Signed" : ". Not Signed") 
    << std::endl;
    return os;
}

void  AForm::be_signed(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.get_Grade() > grade_sign)
        throw GradeTooLowException();
    std::cout << bureaucrat.get_Name() << " signs " << name << std::endl;
    is_signed = true;
}



