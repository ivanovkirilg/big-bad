#include "Printer.hpp"

#include <iomanip>
#include <iostream>
#include <stdexcept>
// #include <ifstream>
#include <fstream>


void Printer::print(const char* file_str)
{
    std::ifstream file(file_str) ;
    if(file) std::cout << file.rdbuf() ;
    else std::cerr << "failed to open file " << std::quoted(file_str) << '\n' ; 
}
