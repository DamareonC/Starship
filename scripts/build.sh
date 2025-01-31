#! /bin/bash

if [ -z "$( ls -A './external/SFML' )" ]
then
    echo "Cloning SFML submodule into external/SFML..."
    git submodule update --init --recursive
    echo "...Finished cloning SFML submodule"
fi

cmake -B build
cmake --build build