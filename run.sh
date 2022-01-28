#!/bin/bash


echo -e "\n\rCompiling...\n\r"

g++  source/Main.cpp source/objects/*.cpp -o ./build/MainCPP.exe --std=c++14 -Wall

echo -e "\n\rCompiled\n\r\n\r"

./build/MainCPP.exe
