# Linux Dependencies

For Arch-based distros (e.g. Arch Linux, Manjaro, Artix), run:
1. `sudo pacman -S libxrandr libxcursor libxi mesa mesa-utils libgudev freetype2 libvorbis flac`

For Debian-based distros (e.g. Debian, Ubuntu, Linux Mint), run:
1. `sudo apt update`
2. `sudo apt install -y libxrandr-dev libxcursor-dev libxi-dev libgl1-mesa-dev libegl1-mesa-dev libudev-dev libfreetype-dev libvorbis-dev libflac-dev`

For Red Hat-based distros (e.g. Fedora, Red Hat Enterprise Linux), run:

1. `sudo dnf install -y libXrandr-devel libXcursor-devel libXi-devel mesa-libGL-devel mesa-libEGL-devel libgudev-devel freetype-devel libvorbis-devel flac-devel`

For Gentoo-based distros (e.g. Gentoo, ChromiumOS, ChromeOS), run:
1. `sudo emerge --sync`
2. `sudo emerge x11-libs/xrandr x11-libs/xcursor x11-libs/libXi media-libs/mesa x11-apps/mesa-progs dev-libs/libgudev media-libs/freetype media-libs/libvorbis media-libs/flac`

For OpenSUSE, run:
1. `sudo zypper install -y libXrandr-devel libXcursor-devel libXi-devel Mesa-libGL-devel Mesa-libEGL-devel libgudev-1_0-devel freetype2-devel libvorbis-devel flac-devel`

For other distros, you need to find the libraries specific to your package manager and install them (search for [these dependencies](https://www.sfml-dev.org/tutorials/3.0/getting-started/build-from-source/#installing-dependencies) on your distro's package manager; try to look for packages with the dependency name and either lib and/or dev in the package name, like seen in the above). Note that some distros might come with these dependencies preinstalled.