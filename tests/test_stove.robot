*** Settings ***
Resource   resources/run_program.resource
Resource   resources/match_output.resource

*** Test Cases ***
Exercise Runs
    Given the arguments are  175  10
    When Program stove is executed successfully
    Then the output shall contain  (*) (*) 25
