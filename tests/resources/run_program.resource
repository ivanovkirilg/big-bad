*** Settings ***
Library    Process

*** Variables ***
@{arguments}    ${None}
${success_arguments}  ../tests/resources/inputs.txt
${success}    Goodbye


*** Keywords ***

the arguments are
    [Arguments]     @{args}
    Set Test Variable  @{arguments}  @{args}

Program ${program} is executed successfully
    ${result} =        Run Process       ./${program}  @{arguments}  stdin=${success_arguments}
    Set Test Variable  ${result}         ${result}
    Log Many           ${result.stderr}  ${result.stdout}
    Should Be Equal    ${result.rc}      ${0}


Program ${program} is executed and fails
    ${result} =          Run Process       ./${program}  @{arguments}
    Set Test Variable    ${result}         ${result}
    Log Many             ${result.stderr}  ${result.stdout}
    Should Not Be Equal  ${result.rc}      ${0}
