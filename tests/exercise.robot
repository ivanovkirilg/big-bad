*** Settings ***
Resource   resources/run_program.resource
Resource   resources/match_output.resource

*** Test Cases ***
Exercise Runs
    When Program exercise is executed successfully
    Then the output shall contain  Hello exercise
