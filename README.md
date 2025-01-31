# Starship

Game is made with C++ and [SFML](https://www.sfml-dev.org/).

## Prerequisites

Make sure you have:
* [CMake](https://cmake.org/download/)
* [Git](https://git-scm.com/downloads)
* A C++17 compiler (e.g. GCC, Clang, MSVC)
* A build system (e.g. Make, Ninja, Visual Studio)

### Linux

For Linux users, SFML requires dependencies to be installed (SFML already comes with these dependences on Windows and macOS).

For Debian-based distros (e.g. Ubuntu, Linux Mint, Pop OS), run:
1. `sudo apt update`
2. `sudo apt install libxrandr-dev libxcursor-dev libxi-dev libgl1-mesa-dev libudev-dev libfreetype-dev libvorbis-dev libflac-dev libegl1-mesa-dev libbdrm-dev libgbm-dev -y`

For Red Hat-based distros (e.g. Fedora, Red Hat Enterprise Linix), run:

1. `sudo dnf install -y libXrandr-devel libXcursor-devel libXi-devel libgudev-devel freetype-devel libvorbis-devel flac-devel mesa-libGL-devel mesa-libEGL-devel libdrm-devel mesa-libgbm-devel`

For other distros, you need to find the libraries specific to your package manager and install them (search for [these dependencies](https://www.sfml-dev.org/tutorials/3.0/getting-started/build-from-source/#installing-dependencies) on your distro's package manager; look for packages; try to look for packages with the dependency name and either lib and/or dev in the package name, like seen in the above). Note that some distros might come with these dependencies preinstalled.

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