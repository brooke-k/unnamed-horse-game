# Unnamed Horse Game

*`Unnamed Horse Game`* (name to be decided at a later date), is a game written in C++ meant to simulate Equine genetics. It is intended to provide a realisitic expression of Equine genetics, primarily in regards to coat colour, in a way that is straighforward enough to be understood without an academic background.

It is currently in progress and not in a playable state, but certain coat colours are able to be calculated with the present source code. Eventually, it will be possible to simulate genetic combinations of multiple equine instances, and predict possible outcomes with a moderate realism.

This README will be updated with new details as they become available in the program, as well as links to guides on how to use them.

## Current Guides

[Coat Encoding](docs/coat-codes.md)

[Commonly Colours as Codes](docs/common-codes.md)

*`Unnamed Horse Game`* uses c11 and c++17.

*`Unnamed Horse Game`* can be compiled from the root directory with the command `g++ ./src/classes/*.cpp ./src/main.cpp -o ./build/main.exe` and exectuted with `./build.exe` following compilation. Ensure `g++-11` is being used to compile the program to prevent compilation errors.
