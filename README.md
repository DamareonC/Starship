# Starship

Starship is a [Space Invaders](https://en.wikipedia.org/wiki/Space_Invaders)-esque game made with C++ and [SFML](https://www.sfml-dev.org/). In the game, you play as a ship, and your goal is to shoot as many enemies (asteroids and missles) as possible. The enemies become faster as time goes on and as you destroy more and more of them. If you get hit, it is game over.

Move around with the WASD keys, and shoot with Space.

## Prerequisites

Make sure you have:
* [CMake](https://cmake.org/download/) (3.27 or later)
* [Git](https://git-scm.com/downloads)
* A C++17 compiler (e.g. GCC, Clang, MSVC)
* A build system (e.g. Make, Ninja, Visual Studio, Xcode)

### Linux

For Linux users, SFML requires dependencies to be installed (SFML already comes with these dependencies on Windows and macOS). Go to [LINUX.md](./docs/LINUX.md) to see what packages to install.

## Building Starship

For a basic build using the default generator and build configurations:

1. Open a terminal
2. Clone this repo with `git clone https://github.com/DamareonC/Starship.git`
3. Move into the directory with `cd Starship`
4. Generate the build files with `cmake -B build`
5. Build Starship with `cmake --build build`* (if you are using Visual Studio or Xcode, you can instead open their respective files and build it in the IDE)

*You can also use the `--parallel <cores>` option to specify how many cores you want to use to build Starship. Just replace `<cores>` with the desired number of cores.

## Running Starship

The executable must be ran from the `Starship` directory, so the executable knows where the `res` folder is. After building Starship, you can run it with:

* macOS/Linux: `build/bin/Starship` or `build/bin/<config>/Starship`
* Windows: `build\bin\Starship.exe` or `build\bin\<config>\Starship.exe`

If the default generator uses a single build configuration (such as Makefile or Ninja), the executable is in `build/bin`.

If the default generator uses multiple build configurations (such as Visual Studio, Xcode, or Ninja Multi-Config), the executable is in `build/bin/<config>`, where `<config>` is either `Debug`, `Release`, `RelWithDebInfo`, or `MinSizeRel` (depending on your default configuration).

Of course, for Visual Studio and Xcode, Starship can be ran in the IDE as well.