#!/bin/bash


echo -e "\n\rCompiling...\n\r"

mcs ./source/core/Main.cs -out:./assembly/Main.exe

echo -e "\n\rCompiled\n\r\n\r"

./assembly/Main.exe
