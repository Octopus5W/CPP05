/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:33:00 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/07/16 21:19:24 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int grade_sign, int grade_execute)
    : name(name), is_signed(false), grade_sign(grade_sign), grade_execute(grade_execute)
{
    if (grade_sign < 1 || grade_execute < 1)
        throw GradeTooHighException();
    else if (grade_sign > 150 || grade_execute > 150)
        throw GradeTooLowException();
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &other)
    : name(other.name), is_signed(other.is_signed), grade_sign(other.grade_sign), grade_execute(other.grade_execute)
{
}
AForm &AForm::operator=(const AForm &other) 
{
    if (this != &other)
    {
        is_signed = other.is_signed;
    }
    return *this;
}

std::string AForm::get_Name() const
{
    return name;
}

int AForm::get_Grade_Sign() const
{
    return grade_sign;
}

int AForm::get_Grade_Execute() const
{
    return grade_execute;
}

bool AForm::get_Is_Signed() const
{
    return is_signed;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Exception : Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Exception : Grade too low";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "Exception : Form not signed";
}



std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
    os << AForm.get_Name() << ", AForm grade to execute " 
    << AForm.get_Grade_Execute() << ", AForm grade to sign " 
    << AForm.get_Grade_Sign() 
    << (AForm.get_Is_Signed() == true ?  ". Signed" : ". Not Signed") 
    << std::endl;
    return os;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (is_signed)
    {
        std::cout << name << " is already signed." << std::endl;
        return;
    }
    else
    {
        if (bureaucrat.get_Grade() > grade_sign)
            throw GradeTooLowException();
        is_signed = true;
        std::cout << bureaucrat.get_Name() << " sign " << name << std::endl;
    }
}



