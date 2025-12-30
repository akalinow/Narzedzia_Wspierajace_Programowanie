#include <iostream>
#include <boost/filesystem.hpp>

int main()
{
    std::cout << "Hello, CMake!" << std::endl;
    std::cout << "Hello, Boost!" << std::endl;

    boost::filesystem::path path = "~/Documents";
    if(path.is_relative())
    {
        std::cout << "Ścieżka względna." << std::endl;
    }
    else
    {
        std::cout << "Ścieżka bezwzględna." << std::endl;
    }

    return 0;
}