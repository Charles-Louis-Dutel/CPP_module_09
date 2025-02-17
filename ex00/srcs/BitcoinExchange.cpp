/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:57:09 by cdutel            #+#    #+#             */
/*   Updated: 2025/02/17 14:36:46 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) : _database()
{
	if (!this->_init_database())
	{
		std::cerr << "Error: couldn't init database" << std::endl;
		this->~BitcoinExchange();
	}
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
		this->_database = inst._database;
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

static bool	is_value_valid(std::string line, int n)
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
	else if (n == 1 && value > 1000)
	{
		std::cerr << "Error: number is too big." << std::endl;
		return (0);
	}
	return (1);
}


/*Private member functions*/
bool	BitcoinExchange::_init_database(void)
{
	std::ifstream	database;
	std::string		line;
	std::string		date;
	unsigned int	i;
	float			value;

	database.open(DATA);
	if (!database.is_open())
	{
		std::cerr << "Error: could not open database" << std::endl;
		return (0);
	}
	std::getline(database, line);
	while (std::getline(database, line))
	{
		if (!is_date_valid(line))
			return (0);
		i = 0;
		while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'))
			i++;
		if (line.find(" | ") != i && line.find_first_of(",") != i)
			return (0);
		if (line[i] == ',' && !(line[i + 1] >= '0' && line[i + 1] <= '9'))
			return (0);
		else if (line [i] == ' ' && (line[i + 1] != '|' || line[i + 2] != ' ' ||
		!(line[i + 3] >= '0' && line[i + 3] <= '9')))
			return (0);
		else
		{
			while (line[i] && (line[i] == ' ' || line[i] == '|' || line[i] == ','))
				i++;
			if (!is_value_valid(&line[i], 0))
				return (0);
			date = line.substr(0, 10);
			value = std::atof(&line[i]);
			this->_database.insert(std::pair<std::string, float>(date, value));
		}
	}
	return (1);
}

void	BitcoinExchange::_print_value(std::string inf_date, float inf_value)
{
	std::map<std::string, float>::iterator	it = this->_database.begin();
	std::map<std::string, float>::iterator	ite = this->_database.end();
	std::map<std::string, float>::iterator	last_it = it;

	if (it == ite)
		return;
	for (; it != ite; it++)
	{
		if (it->first == inf_date)
		{
			std::cout << inf_date << " => " << inf_value << " = " << it->second * inf_value << std::endl;
			return;
		}
		else if (it->first > inf_date)
		{
			if (it == this->_database.begin())
				std::cout << inf_date << " => " << inf_value << " = " << it->second * inf_value << std::endl;
			else
				std::cout << inf_date << " => " << inf_value << " = " << last_it->second * inf_value << std::endl;
			return;
		}
		last_it = it;
	}
	std::cout << inf_date << " => " << inf_value << " = " << last_it->second * inf_value << std::endl;
}


/*Public member functions*/
void	BitcoinExchange::proceed_calc(std::string inf_name)
{
	std::ifstream	infile;
	std::string		line;
	std::string		date;
	unsigned int	i;
	float			value;

	infile.open(inf_name.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: could not open infile" << std::endl;
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
			if (line.find(" | ") != i)
				std::cerr << "Error: bad input => " << line << std::endl;
			else
			{
				if (line [i] == ' ' && (line[i + 1] != '|' || line[i + 2] != ' ' ||
				!(line[i + 3] >= '0' && line[i + 3] <= '9')))
					std::cerr << "Error: bad input => " << line << std::endl;
				else
				{
					while (line[i] && (line[i] == ' ' || line[i] == '|' || line[i] == ','))
						i++;
					if (is_value_valid(&line[i], 1))
					{
						date = line.substr(0, 10);
						value = std::atof(&line[i]);
						this->_print_value(date, value);
					}
				}
			}
		}
	}
}
