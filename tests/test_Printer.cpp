#include "Printer.hpp"

#include "gtest/gtest.h"

#include <stdexcept>

TEST(TestPrinter, IsNotImplemented)
{
    Printer printer;
    EXPECT_THROW(printer.print(), std::logic_error);
}
