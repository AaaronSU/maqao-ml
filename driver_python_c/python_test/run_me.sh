#!/bin/bash

gcc -g -O2 -Wall -fPIC -shared -o my_functions.so my_functions.c -lm -march=native -fno-omit-frame-pointer -fopenmp

# echo "Without MAQAO"
# sudo /bin/python3 driver.py

echo "With MAQAO"
maqao OV -R1 external_libraries=my_functions.so xp=OV1_python --replace -- /bin/python3 driver.py 

rm ./my_functions.so
