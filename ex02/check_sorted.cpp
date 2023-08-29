// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <sstream>

// int main(int argc, char const *argv[])
// {
//     std::string filename = argv[1];

//     std::ifstream file(filename);

//     if (!file.is_open())
//     {
//         std::cout << "Error\n";
//         exit(1);
//     }

//     std::string line;
//     std::string all;

//     while (std::getline(file, line))
//     {
//         all += line;
//         // std::cout << all << std::endl;
//     }
//     std::vector<int> v;
//     std::stringstream ss(all);
//     std::string tmp;

//     while (ss >> tmp)
//     {
//         v.push_back(std::atoi(tmp.c_str()));
//     }

    

//     for (size_t i = 0; i < v.size(); i++)
//     {
//         if ( i + 1 < v.size() && v[i] > v[i + 1])
//         {
//             std::cout << "Error\n";
//             exit(1);
//         }
//     }
    
//     return 0;
// }
