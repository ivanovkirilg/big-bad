#include "VendingMachine.hpp"

#include "gtest/gtest.h"

TEST(TestVendingMachine, Dummy)
{
    VendingMachine vendingMachine;
    
    ASSERT_EQ(vendingMachine.getBalance(), 0);
}

TEST(TestVendingMachine, GetStock)
{
    VendingMachine vendingMachine;
    const std::string itemValid    = "Soda";

    vendingMachine.stockItem("Soda", 5, 50);

    ASSERT_EQ(5, vendingMachine.getItemStock(itemValid));
}

TEST(TestVendingMachine, GetStockNotValid)
{
    VendingMachine vendingMachine;
    const std::string itemNotValid = "Whiskey";

    vendingMachine.stockItem("Soda", 5, 50);

    EXPECT_THROW(vendingMachine.getItemStock(itemNotValid), VendingMachine::VendingMachineError);
}

TEST(TestVendingMachine, GetItemPrice)
{
    VendingMachine vendingMachine;
    const std::string Item      = "Soda";
    int               itemPrice = 50;

    vendingMachine.stockItem(Item, 5, itemPrice);

    EXPECT_EQ(vendingMachine.getItemPrice(Item), itemPrice);
}

TEST(TestVendingMachine, GetItemPriceNotValid)
{
    VendingMachine vendingMachine;
    const std::string Item           = "Soda";
    int               itemPrice      = 50;
    int               itemPriceWrong = 30;

    vendingMachine.stockItem(Item, 5, itemPrice);

    EXPECT_THROW(vendingMachine.getItemPrice("Cola"), VendingMachine::VendingMachineError);
}



