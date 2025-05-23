*** Settings ***
Library    Process
Library    OperatingSystem
Resource   resources/run_program.resource
Resource   resources/match_output.resource

Suite Setup     Copy Directory    %{TEST_DIR}/data    %{BUILD_DIR}/data
Suite Teardown  Remove Directory                      %{BUILD_DIR}/data    recursive=${True}

*** Test Cases ***
Voodoo Is Not Implemented
    Given the arguments are  doesn't matter anyway
    When Program voodooo is executed successfully
    Then the error output shall contain  Not implemented
