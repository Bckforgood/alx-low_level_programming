#!/bin/bash

# Compile all .c files in current directory into .o files
gcc -c *.c

# Create static library from .o files
ar rcs liball.a *.o

# Remove .o files
rm *.o
