cmake_minimum_required(VERSION 3.16)

project(big-bad)

include(ForgetAbout.cmake)

include_directories(src)

###   Build your code here   ###

add_executable(
    vend
    src/main.cpp
    src/VendingMachine.cpp
)


###   Add your unit tests here   ###

add_ut(
    unit_test
    src/VendingMachine.cpp
    tests/test_VendingMachine.cpp
)


###   Add your robot tests here   ###

add_bdd_test(BDD_vend test_vend.robot)
