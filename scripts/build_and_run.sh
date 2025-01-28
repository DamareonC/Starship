if [ ! -d "./external/SFML/.git" ]
then
    echo "WARNING: SFML submodule not found. Cloning SFML submodule into /external..."
    git submodule update --init --recursive
    echo "...Finished cloning SFML submodule"
fi

cmake -S . -B ./build
cmake --build ./build
./bin/Starship