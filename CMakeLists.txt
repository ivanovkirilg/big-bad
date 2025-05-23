cmake_minimum_required(VERSION 3.16)

project(big-bad)

include(ForgetAbout.cmake)

include_directories(src)

###   Build your code here   ###

add_executable(
    voodoo
    src/voodoo.cpp
    src/Printer.cpp
)


###   Add your unit tests here   ###

add_ut(
    TEST_Printer
    src/Printer.cpp
    tests/test_Printer.cpp
)


###   Add your robot tests here   ###

add_bdd_test(BDD_example example.robot)
