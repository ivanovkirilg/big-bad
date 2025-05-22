*** Settings ***
Library    match_file.py


*** Variables ***
${result}        ${None}


*** Keywords ***

the output shall contain
    [Arguments]  ${text}
    Should contain  ${result.stdout}  ${text}

the error output shall contain
    [Arguments]  ${text}
    Should contain  ${result.stderr}  ${text}

the output shall equal
    [Arguments]  ${file}
    Match File Contents    ${result.stdout}    ${file}
