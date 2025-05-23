*** Settings ***
Library  Process


*** Settings ***
Resource   resources/run_program.resource
Resource   resources/match_output.resource

*** Test Cases ***
Vend runs
    When Program vend is executed successfully
    Then the output shall contain  Goodbye

