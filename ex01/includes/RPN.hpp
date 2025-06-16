/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:40:53 by cdutel            #+#    #+#             */
/*   Updated: 2025/06/16 15:24:02 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <stdexcept>
# include <cstdlib>

class	RPN
{
	public:
		RPN(void);
		RPN(RPN const &copy);
		~RPN(void);

		RPN	&operator=(RPN const &inst);

		void	proceed_calc(std::string input);

		class BadInputException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Error: bad input";
				}
		};

		class DivideByZeroException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Error: dividing by zero is impossible";
				}
		};

	private:
	std::stack<int>	_mystack;
};

#endif
