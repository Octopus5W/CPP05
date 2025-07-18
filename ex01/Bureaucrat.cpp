/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:33:00 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/07/16 22:25:58 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    : name("Default Bureaucrat"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade)
{
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
	    grade = other.grade;
    }
    return *this;
}

std::string Bureaucrat::get_Name() const
{
    return name;
}

int Bureaucrat::get_Grade() const
{
    return grade;
}

void Bureaucrat::increment_Grade()
{
        if (grade <= 1)
            throw GradeTooLowException();
        else
            grade--;
}

void Bureaucrat::decrement_Grade()
{
        if (grade >= 150)
            throw GradeTooHighException();
        grade++;
}

const char* Bureaucrat::GradeTooHighException::what()
{
    return "Exception : Grade out of range";
}

const char* Bureaucrat::GradeTooLowException::what()
{
    return "Exception : Grade out of range";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.get_Name() << ", bureaucrat grade " << bureaucrat.get_Grade() << std::endl;
    return os;
}



