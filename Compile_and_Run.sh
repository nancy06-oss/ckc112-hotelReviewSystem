#!/bin/bash
# Compilation script for Hotel Review System
# Compiles all header and implementation files

echo "Compiling Hotel Review System..."
g++ Review.h Review.cpp User.h User.cpp Traveler.h Traveler.cpp Hotel.h Hotel.cpp HotelSystem.h HotelSystem.cpp main.cpp -o HotelReviewSystem.elf

if [ $? -eq 0 ]; then
    echo "Compilation successful!"
    echo "Running the program..."
    ./HotelReviewSystem.elf
else
    echo "Compilation failed!"
    exit 1
fi