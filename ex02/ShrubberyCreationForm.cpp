/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ShrubberyCreationForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:33:00 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/07/16 21:19:24 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

 ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string  ShrubberyCreationForm::get_Name() const
{
    return name;
}

int  ShrubberyCreationForm::get_Grade_Sign() const
{
    return grade_sign;
}

int  ShrubberyCreationForm::get_Grade_Execute() const
{
    return grade_execute;
}

const char*  ShrubberyCreationForm::GradeTooHighException::what()
{
    return "Exception : Grade too high";
}

const char*  ShrubberyCreationForm::GradeTooLowException::what()
{
    return "Exception : Grade too low";
}

std::ostream &operator<<(std::ostream &os, const  ShrubberyCreationForm & ShrubberyCreationForm)
{
    os <<  ShrubberyCreationForm.get_Name() << ",  ShrubberyCreationForm grade to execute " 
    <<  ShrubberyCreationForm.get_Grade_Execute() << ",  ShrubberyCreationForm grade to sign " 
    <<  ShrubberyCreationForm.get_Grade_Sign() 
    << ( ShrubberyCreationForm.get_Grade_Sign() == 1 ?  ". Signed" : ". Not Signed") 
    << std::endl;
    return os;
}

void  ShrubberyCreationForm::be_signed(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.get_Grade() > grade_sign)
        throw GradeTooLowException();
    std::cout << bureaucrat.get_Name() << " signs " << name << std::endl;
    is_signed = true;
}



