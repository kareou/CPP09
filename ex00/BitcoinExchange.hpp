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
    int get_price(std::string date);
public:
    void read_data(std::string filename);
    void read_file(std::string filename);
    BitcoinExchange(/* args */);
    ~BitcoinExchange();
};


#endif 