/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:21:44 by mkhairou          #+#    #+#             */
/*   Updated: 2023/08/23 11:21:45 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "usage: ./bitcoin [file]" << std::endl;
    }
    else
    {
        std::string filename = argv[1];
        BitcoinExchange b;
        b.read_file();
        b.read_data(filename);
    }

    return 0;
}
