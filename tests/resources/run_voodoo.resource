*** Settings ***
Library    Process


*** Variables ***
${result}        ${None}


*** Keywords ***

the arguments are
    [Arguments]     @{args}
    Set Test Variable  @{arguments}  @{args}

Voodooo is executed successfully
    ${result} =        Run Process  ./voodoo  @{arguments}
    Set Test Variable  ${result}         ${result}
    Log Many           ${result.stderr}  ${result.stdout}
    Should Be Equal    ${result.rc}      ${0}

Voodooo is executed and fails
    ${result} =          Run Process  ./voodoo  @{arguments}
    Set Test Variable    ${result}         ${result}
    Log Many             ${result.stderr}  ${result.stdout}
    Should Not Be Equal  ${result.rc}      ${0}
