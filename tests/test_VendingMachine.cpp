#include "VendingMachine.hpp"

#include "gtest/gtest.h"

TEST(TestVendingMachine, get_balance)
{
    VendingMachine vendingMachine;
    
    ASSERT_EQ(vendingMachine.getBalance(), 0);
}

TEST(TestVendingMachine, insert_coin_correct)
{
    VendingMachine vendingMachine;
    auto money = 25;
    vendingMachine.insertCoin(money);

    ASSERT_EQ(vendingMachine.getBalance(), money);
}

TEST(TestVendingMachine, insert_coin_negative_number)
{
    VendingMachine vendingMachine;
    auto money = -25;

    EXPECT_THROW(vendingMachine.insertCoin(money), VendingMachine::VendingMachineError );
}

