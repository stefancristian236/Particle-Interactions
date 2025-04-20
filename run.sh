#!/bin/bash

# Compile the SFML application
g++ main.cpp -o particle_simulation -lsfml-graphics -lsfml-window -lsfml-system

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the application..."
    # Run the application
    ./particle_simulation
else
    echo "Compilation failed."
fi