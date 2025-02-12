/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:57:09 by cdutel            #+#    #+#             */
/*   Updated: 2025/02/12 05:29:51 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) : _database()
{
	this->_init_database();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) : _database(copy._database)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange(void)
{
}


/*Operator overload*/
BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &inst)
{
	if (this != &inst)
	{
	}
	return (*this);
}


/*Non member functions*/
static bool	is_date_valid(std::string line)
{
	int	i = 0;
	int	year;
	int	day;
	int	month;

	while (line[i] && (line[i] >= '0' && line[i] <= '9'))
		i++;
	if (i != 4 || line[i] != '-')
		return (0);
	year = std::atoi(&line[i - 4]);
	i++;

	while (line[i] && (line[i] >= '0' && line[i] <= '9'))
		i++;
	if (i != 7 || line[i] != '-')
		return (0);
	month = std::atoi(&line[i - 2]);
	i++;

	while (line[i] && (line[i] >= '0' && line[i] <= '9'))
		i++;
	if (i != 10 && (line[i] != ' ' || line[i] != ','))
		return (0);
	day = std::atoi(&line[i - 2]);

	int days_in_february = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
	switch (month)
	{
		case 2:
			if ((days_in_february == 28 && (day < 1 || day > 28)) ||
				(days_in_february == 29 && (day < 1 || day > 29)))
				return (0);
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day < 1 || day > 31)
				return (0);
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day < 1 || day > 30)
				return (0);
			break;
		default:
			return (0);
	}
	return (1);
}

static bool	is_value_valid(std::string line)
{
	int		i = 0;
	int		dot = 0;
	float	value;

	while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '.'))
	{
		if ((i == 0 && line[i] == '.') || (line[i] == '.' && dot >= 1))
		{
			std::cerr << "Error: bad input: " << line << std::endl;
			return (0);
		}
		else if (line[i] == '.' && dot == 0)
			dot++;
		i++;
	}
	if (line[i])
	{
		std::cerr << "Error: bad input: " << line << std::endl;
		return (0);
	}
	value = std::atof(&line[0]);
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (0);
	}
	else if (value > 1000)
	{
		std::cerr << "Error: number is too big." << std::endl;
		return (0);
	}
	return (1);
}

/*Member functions*/
void	BitcoinExchange::_init_database(void)
{
	std::ifstream	infile;
	std::string		line;
	unsigned int	i;

	infile.open(INF);
	if (!infile.is_open())
	{
		std::cerr << "Error: could not open database" << std::endl;
		return;
	}
	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		if (!is_date_valid(line))
			std::cerr << "Error: date isn't valid: " << line << std::endl;
		else
		{
			i = 0;
			while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'))
				i++;
			if (line.find(" | ") != i && line.find_first_of(",") != i)
				std::cerr << "Error: bad input => " << line << std::endl;
			else
			{
				if (line[i] == ',' && !(line[i + 1] >= '0' && line[i + 1] <= '9'))
					std::cerr << "Error: bad input => " << line << std::endl;
				else if (line [i] == ' ' && (line[i + 1] != '|' || line[i + 2] != ' ' ||
				!(line[i + 3] >= '0' && line[i + 3] <= '9')))
					std::cerr << "Error: bad input => " << line << std::endl;
				else
				{
					while (line[i] && (line[i] == ' ' || line[i] == '|' || line[i] == ','))
						i++;
					if (is_value_valid(&line[i]))
					{
					}
				}
			}
		}
	}
}
