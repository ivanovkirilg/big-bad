*** Settings ***
Library    Process

*** Variables ***
@{arguments}    ${None}
${file_input}  ./tests/resources/in.txt
${std_input}    ${None}

*** Keywords ***

the arguments are
    [Arguments]     @{args}
    Set Test Variable  @{arguments}  @{args}

Program ${program} is executed successfully
    ${result} =        Run Process       ./${program}  @{arguments}  stdin=${file_input}
    Set Test Variable  ${result}         ${result}
    Log Many           ${result.stderr}  ${result.stdout}
    Should Be Equal    ${result.rc}      ${0}

set test input
    [Arguments]  @{input}  
    ${joined_input} =  Catenate  @{input}
    Set Test Variable  @{std_input}  @{input} ${joined_input}

Program ${program} is executed and fails
    ${result} =          Run Process       ./${program}  @{arguments}
    Set Test Variable    ${result}         ${result}
    Log Many             ${result.stderr}  ${result.stdout}
    Should Not Be Equal  ${result.rc}      ${0}
