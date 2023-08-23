/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:21:41 by mkhairou          #+#    #+#             */
/*   Updated: 2023/08/23 11:23:24 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <ctime>
#include <algorithm>

class BitcoinExchange
{
private:
    std::map<std::string, double> _map;
    int check_date(std::string date);
    int month_date(int year, int month);
    int check_line(std::string key, int indecator);
    double get_price(std::string date);
public:
    void read_data(std::string filename);
    void read_file();
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &cpy);
    BitcoinExchange &operator=(BitcoinExchange const &cpy);
    ~BitcoinExchange();
};


#endif
