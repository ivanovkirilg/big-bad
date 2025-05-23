#include <iostream>
#include <string>
#include <limits>
#include "VendingMachine.hpp"

void showItems(const VendingMachine& vm)
{
    std::cout << "\nAvailable items:\n";
    bool any = false;
    for (const std::string& item : {"Soda", "Chips", "Candy"})
    {
        try
        {
            int stock = vm.getItemStock(item);
            int price = vm.getItemPrice(item);
            if (stock > 0)
            {
                std::cout << " - " << item << ": " << stock << " in stock, price: " << price << " cents\n";
                any = true;
            }
        }
        catch (const VendingMachine::VendingMachineError&)
        {
            // Item not found, skip
        }
    }
    if (!any)
        std::cout << " (No items in stock)\n";
}

void clearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void adminMenu(VendingMachine& vm)
{
    std::cout << "\n--- Admin: Stock Items ---\n";
    std::string item;
    int count, price;
    std::cout << "Enter item name: ";
    std::getline(std::cin, item);
    std::cout << "Enter count: ";
    std::cin >> count;
    std::cout << "Enter price (cents): ";
    std::cin >> price;
    clearInput();
    try
    {
        vm.stockItem(item, count, price);
        std::cout << "Stocked " << count << " of " << item << " at " << price << " cents each.\n";
    }
    catch (const VendingMachine::VendingMachineError& e)
    {
        std::cout << "Error: " << e.what() << "\n";
    }
}

int main()
{
    VendingMachine vm;
    // Pre-stock some items for demo
    vm.stockItem("Soda", 5, 125);
    vm.stockItem("Chips", 3, 100);
    vm.stockItem("Candy", 10, 65);

    std::cout << "Welcome to the Vending Machine!\n";
    while (true)
    {
        // Default state: buy menu
        showItems(vm);
        std::cout << "\nYour balance: " << vm.getBalance() << " cents\n";
        std::cout << "Enter item name to buy, 'refund' to get your coins back, or 'exit' to quit:\n";
        std::cout << "> ";
        std::string input;
        std::getline(std::cin, input);

        if (input == "exit")
        {
            std::cout << "Goodbye!\n";
            break;
        }
        else if (input == "refund")
        {
            int refund = vm.refund();
            std::cout << "Refunded: " << refund << " cents\n";
            continue;
        }
        else if (input == "admin")
        {
            adminMenu(vm);
            continue;
        }
        else
        {
            // Try to buy an item
            std::string item = input;
            try
            {
                vm.selectItem(item);
            }
            catch (const VendingMachine::VendingMachineError& e)
            {
                std::cout << "Error: " << e.what() << "\n";
                continue;
            }

            int price = 0;
            try
            {
                price = vm.getItemPrice(item);
            }
            catch (...)
            {
                std::cout << "Unexpected error.\n";
                continue;
            }

            // Insert coins until enough
            while (vm.getBalance() < price)
            {
                std::cout << "Insert coins (cents, or 0 to cancel). Needed: " << (price - vm.getBalance()) << " cents\n> ";
                int cents;
                std::cin >> cents;
                clearInput();
                if (cents == 0)
                {
                    std::cout << "Purchase cancelled.\n";
                    vm.refund();
                    break;
                }
                try
                {
                    vm.insertCoin(cents);
                }
                catch (const VendingMachine::VendingMachineError& e)
                {
                    std::cout << "Error: " << e.what() << "\n";
                }
            }
            if (vm.getBalance() >= price)
            {
                try
                {
                    vm.dispense();
                    std::cout << "Enjoy your " << item << "! Remaining balance: " << vm.getBalance() << " cents\n";
                }
                catch (const VendingMachine::VendingMachineError& e)
                {
                    std::cout << "Error: " << e.what() << "\n";
                }
            }
        }
    }

    return 0;
}