@echo off
cls

set /p QNUM="Enter Question Number: "

@REM echo "%cd%\Programs\LC %QNUM%"

if not exist "%cd%\Programs\LC %QNUM%" (
    echo Folder not present
    echo Creating new folder at "%cd%\Programs\LC %QNUM%"
    mkdir "%cd%\Programs\LC %QNUM%" 
) else (
    echo Folder already present
)

