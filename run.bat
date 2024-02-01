@echo off

set SOURCE_FILE=main

set EXECUTABLE_FILE=%SOURCE_FILE%.exe

set COMPILER=g++

rem Compile the C++ code
%COMPILER% %SOURCE_FILE%.cpp -o %EXECUTABLE_FILE%

if %errorlevel% neq 0 (
    echo Compilation failed.
    exit /b %errorlevel%
)

echo Compilation successful. Executing %EXECUTABLE_FILE%...

rem Pause for 2 seconds
timeout /t 2 >nul

rem Execute the compiled program
%EXECUTABLE_FILE%

rem Pause to keep the command prompt window open
pause
