#include <iostream>
#include <string>
#include "Printer.hpp"



int main(int argc, char* argv[])
{
    // std::cerr << "Not implemented\n";

    Printer pr;

    std::string fileName = pr.UI();

    pr.print(fileName);
    return EXIT_SUCCESS;
}
