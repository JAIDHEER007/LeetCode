@echo off
cls

set /p QNUM="Enter Question Number: "

@REM echo "%cd%\Programs\LC %QNUM%"

if not exist "%cd%\Programs\LC %QNUM%" (
    echo Folder not present
    echo Creating new folder at "%cd%\Programs\LC %QNUM%"
    mkdir "%cd%\Programs\LC %QNUM%" 
    echo Enter Test Case Here > "%cd%\Programs\LC %QNUM%"\input1.txt
    echo Enter Test Case Here > "%cd%\Programs\LC %QNUM%"\input2.txt
    echo Enter Test Case Here > "%cd%\Programs\LC %QNUM%"\input3.txt
    echo Enter Test Case Here > "%cd%\Programs\LC %QNUM%"\input4.txt
    echo Enter Test Case Here > "%cd%\Programs\LC %QNUM%"\input5.txt
) else (
    echo Folder already present
)



