/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:56:00 by cdutel            #+#    #+#             */
/*   Updated: 2025/02/12 02:30:03 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <utility>
# include <cstdlib>

# define INF "bad_date.csv"

class	BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &copy);
		~BitcoinExchange(void);

		BitcoinExchange	&operator=(BitcoinExchange const &inst);

	private:
		void	_init_database(void);

		std::map<std::string, float>	_database;
};

#endif
