*** Settings ***
Resource   resources/run_program.resource
Resource   resources/match_output.resource

*** Test Cases ***
Vend runs
    Fail  missing a keyword for input
    # When Program vend is executed successfully
    # Then the output shall contain  Welcome to the Vending Machine!
