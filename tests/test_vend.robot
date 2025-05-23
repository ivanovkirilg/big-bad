*** Settings ***
Resource   resources/run_program.resource
Resource   resources/match_output.resource
Library    resources/set_input.py

*** Test Cases ***
The correct price is displayed for an existing item
    Given the input is    exit
    When Program vend is executed successfully
    Then the output shall contain  Soda: 5 in stock, price: 125 cents

Rejects nonpositive coins
    Given the input is
    ...  Soda\n
    ...  -5\n
    ...  exit\n
    ...  exit\n
    When Program vend is executed successfully
    Then the output shall contain  Inserted coin value must be positive
