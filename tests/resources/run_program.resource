*** Settings ***
Library    Process

*** Variables ***
@{arguments}    ${EMPTY}
${std_input}    ${None}

*** Keywords ***

the arguments are
    [Arguments]     @{args}
    Set Test Variable  @{arguments}  @{args}

# the input is
#     [Arguments]     @{input}    
#     ${joined_input} =  Catenate  SEPARATOR=  @{input}
#     Set Test Variable  ${std_input}  ${joined_input}

Program ${program} is executed successfully
    Log                ${std_input}
    ${result} =        Run Process       ./${program}  @{arguments}  stdin=${std_input}
    Set Test Variable  ${result}         ${result}
    Log Many           ${result.stderr}  ${result.stdout}
    Should Be Equal    ${result.rc}      ${0}

Program ${program} is executed and fails
    ${result} =          Run Process       ./${program}  @{arguments}  stdin=${std_input}
    Set Test Variable    ${result}         ${result}
    Log Many             ${result.stderr}  ${result.stdout}
    Should Not Be Equal  ${result.rc}      ${0}
