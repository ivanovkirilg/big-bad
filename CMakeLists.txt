cmake_minimum_required(VERSION 3.16)

project(big-bad)

include(ForgetAbout.cmake)

include_directories(src)

###   Build your code here   ###

add_executable(
    exercise
    src/main.cpp
)


###   Add your unit tests here   ###

add_ut(
    unit_test
    src/Exercise.cpp
    tests/test_Exercise.cpp
)


###   Add your robot tests here   ###

add_bdd_test(BDD_exercise exercise.robot)
