@echo off

dir /b ".\external\SFML" | findstr "^" > nul || (
    echo Cloning SFML submodule into external\SFML...
    git submodule update --init --recursive
    echo ...Finished cloning SFML submodule
)

cmake -B build
cmake --build build