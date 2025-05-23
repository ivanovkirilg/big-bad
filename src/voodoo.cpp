#include <iostream>
#include "Printer.hpp"

int main(int argc, char* argv[])
{
    // std::cerr << "Not implemented\n";
    Printer p;

    if(argc == 2) p.print(argv[1]) ;

    return EXIT_SUCCESS;
}
