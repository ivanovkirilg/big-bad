#include <iostream>
#include <fstream>

#include "Printer.hpp"

#include <stdexcept>
#include <string>


void Printer::print(std::string FILE_NAME)
{
    // throw std::logic_error("Printer is not implemented");
    std::ifstream file(FILE_NAME);
    if (file.is_open()) {
        std::cout << file.rdbuf();
        file.close();
    } else {
        std::cout << "Unable to open file";
    }
}

std::string Printer::UI()
{
    std::string fileName;
    std::cout << "Hello type the file name: "; 
    std::cin >> fileName;
    std::string pathSuffix = "../tests/data/";
    std::cout << "Here is the content : " << "\n";
    return pathSuffix + fileName;
}



