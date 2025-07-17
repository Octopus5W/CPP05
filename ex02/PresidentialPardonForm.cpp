/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    PresidentialPardonForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:33:00 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/07/16 21:19:24 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string  PresidentialPardonForm::get_Name() const
{
    return name;
}

int  PresidentialPardonForm::get_Grade_Sign() const
{
    return grade_sign;
}

int  PresidentialPardonForm::get_Grade_Execute() const
{
    return grade_execute;
}

const char*  PresidentialPardonForm::GradeTooHighException::what()
{
    return "Exception : Grade too high";
}

const char*  PresidentialPardonForm::GradeTooLowException::what()
{
    return "Exception : Grade too low";
}

std::ostream &operator<<(std::ostream &os, const  PresidentialPardonForm & PresidentialPardonForm)
{
    os <<  PresidentialPardonForm.get_Name() << ",  PresidentialPardonForm grade to execute " 
    <<  PresidentialPardonForm.get_Grade_Execute() << ",  PresidentialPardonForm grade to sign " 
    <<  PresidentialPardonForm.get_Grade_Sign() 
    << ( PresidentialPardonForm.get_Grade_Sign() == 1 ?  ". Signed" : ". Not Signed") 
    << std::endl;
    return os;
}

void  PresidentialPardonForm::be_signed(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.get_Grade() > grade_sign)
        throw GradeTooLowException();
    std::cout << bureaucrat.get_Name() << " signs " << name << std::endl;
    is_signed = true;
}



