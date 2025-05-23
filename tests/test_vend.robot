*** Settings ***
Resource   resources/run_program.resource
Resource   resources/match_output.resource



*** Variables ***


*** Test Cases ***
Vend runs
    # Fail  missing a keyword for input
    Given set test input
    ...  Soda\n
    ...  200\n
    ...  exit\n
    When Program vend is executed successfully
    Then the output shall contain  Welcome to the Vending Machine!

