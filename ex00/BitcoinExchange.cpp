#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

int BitcoinExchange::month_date(int year, int month)
{
    if (month == 2)
    {
        if (year % 4 == 0)
            return 29;
        else
            return 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else
        return 31;
}

int BitcoinExchange::get_price(std::string date)
{
    std::map<std::string, double>::iterator it = _map.lower_bound(date);
    if (it != _map.begin())
    {
        if (it->first != date)
            --it;
        return it->second;
    }
    return it->second;
}

int BitcoinExchange::check_date(std::string date)
{

    std::time_t t = std::time(0);

    std::tm *now = std::localtime(&t);
    int year_now = now->tm_year + 1900;

    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return 1;
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    int year_i = std::atoi(year.c_str());
    int month_i = std::atoi(month.c_str());
    int day_i = std::atoi(day.c_str());
    if (year_i > year_now || year_i < 2009)
        return 1;
    if (month_i > 12 || month_i < 1)
        return 1;
    int days_in_month = month_date(year_i, month_i);
    if (day_i > days_in_month || day_i < 1)
        return 1;

    return 0;
}

int BitcoinExchange::check_line(std::string key, int indecator)
{
    std::string date;
    std::string price;

    std::stringstream ss(key);
    if (indecator == 0)
    {
        ss >> date;
        ss >> price;
        ss >> price;
    }
    else
    {
        std::getline(ss, date, ',');
        std::getline(ss, price, ',');
        date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
        price.erase(std::remove(price.begin(), price.end(), ' '), price.end());
    }
    if (date == "" || price == "")
        return 1;
    char *not_digit;
    double date_d = strtod(date.c_str(), &not_digit);
    if (*not_digit != '\0' && *not_digit != '-')
        return 1;
    if (check_date(date))
        return 1;
    char *leftover;
    double price_d = strtod(price.c_str(), &leftover);
    if (*leftover != '\0' || price_d < 0 || price_d > 1000)
        return 1;
    return 0;
}

void BitcoinExchange::read_data(std::string filename)
{
    std::string line;

    std::ifstream myfile(filename.c_str());
    if (myfile.is_open())
    {
        while (std::getline(myfile, line))
        {
            if (check_line(line, 0) == 0)
            {
                std::stringstream ss(line);
                std::string date;
                std::string price;
                ss >> date;
                ss >> price;
                ss >> price;
                std::cout << date + "=> " + price + " = ";
                int total = get_price(date);

                std::cout << total * std::atoi(price.c_str()) << std::endl;
            }
            else
            {
                std::cerr << "Invalid line" << std::endl;
                exit(1);
            }
        }
        myfile.close();
    }
    else
    {
        std::cerr << "Unable to open file" << std::endl;
    }
}

void BitcoinExchange::read_file(std::string filename)
{
    std::string line;

    std::ifstream myfile(filename.c_str());
    if (myfile.is_open())
    {
        while (std::getline(myfile, line))
        {
            if (check_line(line, 1) == 0)
            {
                std::stringstream ss(line);
                std::string date;
                std::string price;
                std::getline(ss, date, ',');
                std::getline(ss, price, ',');
                date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
                price.erase(std::remove(price.begin(), price.end(), ' '), price.end());
                _map.insert(std::pair<std::string, double>(date, std::strtod(price.c_str(), NULL)));
            }
            else
            {
                std::cerr << "Invalid line" << std::endl;
                exit(1);
            }
        }
        myfile.close();
    }
    else
    {
        std::cerr << "Unable to open file" << std::endl;
    }
}
