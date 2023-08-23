#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        std::cerr << "usage: ./bitcoin [file]" << std::endl;
    }
    else
    {
        std::string filename = argv[1];
        std::string line = argv[2];
        BitcoinExchange b;
        b.read_file(filename);
        b.read_data(line);
    }
    
    return 0;
}
