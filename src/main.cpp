#include "Stove.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <temperature> <timer>\n";
        return EXIT_FAILURE;
    }

    int temperature = std::stoi(argv[1]);
    int timer = std::stoi(argv[2]);

    Stove stove{3};
    
    stove.turnOn(temperature, timer);

    std::string cookingLight = "(*) ";
    std::cout << cookingLight;
    while (! stove.waitReady())
    {
        std::cout << '\n' << cookingLight;
    }
    std::cout << "\n( ) OFF\n";

    return EXIT_SUCCESS;
}
