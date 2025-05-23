cmake_minimum_required(VERSION 3.16)

project(big-bad)

include(ForgetAbout.cmake)

include_directories(src)

###   Build your code here   ###

add_executable(
    stove
    src/main.cpp
    src/Stove.cpp
)


###   Add your unit tests here   ###

add_ut(
    unit_test
    src/Stove.cpp
    tests/test_Stove.cpp
)


###   Add your robot tests here   ###

add_bdd_test(BDD_exercise test_stove.robot)
