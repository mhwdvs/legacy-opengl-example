# C++ GLFW Boilerplate

A general purpose C++ GLFW boilerplate. 

Comes preconfigured with Google Test/CTest and basic project structure

## Cloning

This project utilises *git submodules*. To both clone this **and the required submodules** run `git clone --recurse-submodules https://github.com/mhwdvs/sdl2-boilerplate`

Alternatively, you can run `git submodules init && git submodules update` if you have already cloned the repo without submodules

## Dependencies

The following python3 dependencies must be installed on all platforms;

`pip3 install jinja2`

### Linux

Ubuntu/Debian:

- `sudo apt install git cmake ninja-build xorg-dev libwayland-dev wayland-protocols extra-cmake-modules build-essential autoconf automake libtool pkg-config libasound2-dev libpulse-dev libaudio-dev libjack-dev libx11-dev libxext-dev libxrandr-dev libxcursor-dev libxi-dev libxinerama-dev libxxf86vm-dev libxss-dev libgl1-mesa-dev libdbus-1-dev libudev-dev libgles2-mesa-dev libegl1-mesa-dev libibus-1.0-dev fcitx-libs-dev libsamplerate0-dev libsndio-dev libwayland-dev libxkbcommon-dev libdrm-dev libgbm-dev`

Fedora:

- `sudo dnf install git cmake clang libX11-devel libXrandr-devel libXinerama-devel libXcursor-devel libXi-devel`

### MacOS

TODO (generally install the packages/libraries that CMake complains are missing using typical MacOS tooling [eg `brew`])

### Windows

- MSVC compiler

## Building

Generate Ninja build files:
`cmake -S . -B build --DCMAKE_BUILD_TYPE=Release -G Ninja`

Build with Ninja
`cmake --build build`

## Run

### Linux/MacOS

`cd build/src/ && ./Main`

### Windows

`cd build/src/ && Main.exe`

## Compatability

### CMake generators

It is recommended that Ninja and the `ninja` CMake generator is used (`-G Ninja`). Theoretically any generator can be used, but some generators will use odd directory structures that will interfere with things such as copying resources into the correct places in the build directory.
