# Starship

Game is made with C++ and [SFML](https://www.sfml-dev.org/).

## Prerequisites

Make sure you have:
* [CMake](https://cmake.org/download/) (3.27 or later)
* [Git](https://git-scm.com/downloads)
* A C++17 compiler (e.g. GCC, Clang, MSVC)
* A build system (e.g. Make, Ninja, Visual Studio, Xcode)

### Linux

For Linux users, SFML requires dependencies to be installed (SFML already comes with these dependences on Windows and macOS). Go to [LINUX.md](./docs/LINUX.md) to see what packages to install.

## Building Starship

For a basic build using the default generator and build configurations:

1. Open a terminal
2. Clone this repo with `git clone https://github.com/DamareonC/Starship.git`
3. Move into the directory with `cd Starship`
4. Generate the build files with `cmake -B build`
5. Build Starship with `cmake --build build --parallel 8` (if you are using Visual Studio or Xcode, you can instead open their respective files and build it in the IDE)

## Running Starship

The executable must be ran from the `Starship` directory, so the executable knows where the `res` folder is. After building Starship, you can run it with:

* macOS/Linux: `build/bin/Starship` or `build/bin/<config>/Starship`
* Windows: `build\bin\Starship.exe` or `build\bin\<config>\Starship.exe`

If the default generator uses a single build configuration (such as Makefile or Ninja), the executable is in `build/bin`.

If the default generator uses multiple build configurations (such as Visual Studio, Xcode, or Ninja Multi-Config), the executable is in `build/bin/<config>`, where `<config>` is either `Debug`, `Release`, `RelWithDebInfo`, or `MinSizeRel` (depending on your default configuration).

Of course, for Visual Studio and Xcode, Starship can ran in the IDE as well.