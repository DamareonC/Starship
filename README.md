# Starship

Game is build with C++ and [SFML](https://www.sfml-dev.org/).

## Prerequisites

Make sure you have [CMake](https://cmake.org/download/) and [Git](https://git-scm.com/downloads) installed.

For Linux users, SFML requires dependencies to be installed (SFML already comes with these dependences on Windows and macOS).

For Debian-based distros (e.g. Ubuntu, Linux Mint, Pop OS), run:
1. `sudo apt update`
2. `sudo apt install libxrandr-dev libxcursor-dev libudev-dev libfreetype-dev libflac-dev libvorbis-dev libgl1-mesa-dev libegl1-mesa-dev libfreetype-dev`

## Building Starship

For a basic build using the default generator and build configurations:

1. Open a terminal
2. Clone this repo with `git clone https://github.com/DamareonC/Starship.git`
3. Move into the directory with `cd Starship`
4. Build the project with `scripts\build.bat` (Windows) or `. scripts/build.sh` (macOS/Linux)

## Running Starship

The executable must be ran from the `Starship` directory, so the executable knows where the `res` folder is. After building Starship, you can run it with:

* macOS/Linux: `build/bin/Starship` or `build/bin/<config>/Starship`
* Windows: `build\bin\Starship.exe` or `build\bin\<config>\Starship.exe`

If the default generator uses a single build configuration (such as Makefile or Ninja), the executable is in `build/bin`.

If the default generator uses multiple build configurations (such as Visual Studio, Xcode, or Ninja Multi-Config), the executable is in `build/bin/<config>`, where `<config>` is either `Debug`, `Release`, `RelWithDebInfo`, or `MinSizeRel` (depending on your default configuration).