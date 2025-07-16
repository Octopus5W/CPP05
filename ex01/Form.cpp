/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:33:00 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/07/16 21:19:24 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int grade_sign, int grade_execute)
    : name(name), is_signed(false), grade_sign(grade_sign), grade_execute(grade_execute)
{
    if (grade_sign < 1 || grade_execute < 1)
        throw GradeTooHighException();
    else if (grade_sign > 150 || grade_execute > 150)
        throw GradeTooLowException();
}

Form::~Form()
{
}

Form::Form(const Form &other)
    : name(other.name), is_signed(other.is_signed), grade_sign(other.grade_sign), grade_execute(other.grade_execute)
{
}
Form &Form::operator=(const Form &other) 
{
    if (this != &other)
    {
        is_signed = other.is_signed;
    }
    return *this;
}

std::string Form::get_Name() const
{
    return name;
}

int Form::get_Grade_Sign() const
{
    return grade_sign;
}

int Form::get_Grade_Execute() const
{
    return grade_execute;
}

const char* Form::GradeTooHighException::what()
{
    return "Exception : Grade too high";
}

const char* Form::GradeTooLowException::what()
{
    return "Exception : Grade too low";
}

std::ostream &operator<<(std::ostream &os, const Form &Form)
{
    os << Form.get_Name() << ", Form grade to execute " 
    << Form.get_Grade_Execute() << ", Form grade to sign " 
    << Form.get_Grade_Sign() 
    << (Form.get_Grade_Sign() == 1 ?  ". Signed" : ". Not Signed") 
    << std::endl;
    return os;
}

void Form::be_signed(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.get_Grade() > grade_sign)
        throw GradeTooLowException();
    std::cout << bureaucrat.get_Name() << " signs " << name << std::endl;
    is_signed = true;
}



