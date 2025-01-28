@echo off

if not exist .\external\SFML\.git (
    echo SFML submodule not found. Cloning SFML submodule into /external...
    git submodule update --init --recursive
    echo ...Finished cloning SFML submodule
)

cmake -S . -B .\build
cmake --build .\build
.\bin\Debug\Starship.exe