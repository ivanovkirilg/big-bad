#include "VendingMachine.hpp"

#include "gtest/gtest.h"

TEST(TestVendingMachine, Dummy)
{
    VendingMachine vendingMachine;
    
    ASSERT_EQ(vendingMachine.getBalance(), 0);
}
