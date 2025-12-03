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

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}


RobotomyRequestForm::~RobotomyRequestForm()
{
}


void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!get_Is_Signed())
        throw AForm::GradeTooLowException();
    if (executor.get_Grade() > get_Grade_Execute())
        throw AForm::GradeTooLowException();
    std::cout << "*****drilling*****noises****" << std::endl;
    if (rand() % 2)
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "The robotomy on " << target << " has failed." << std::endl;
}



