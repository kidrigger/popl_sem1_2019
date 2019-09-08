#!/usr/bin/env bash

gcc inheritance.c -o inheritance_c
gcc hiding.c hiding_main.c -o hiding_c
g++ -std=c++14 inheritance.cpp -o inheritance_cpp
