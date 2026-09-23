/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:43:50 by adeestev          #+#    #+#             */
/*   Updated: 2026/09/23 15:23:16 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
		~PresidentialPardonForm();

		void execute(Bureaucrat const & executor) const;
};

#endif
