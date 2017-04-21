#!/bin/bash

#colors tests
g++ -std=c++11 ./testingfilesrc/color.cpp -o ./testingfilesrc/color.out;
./testingfilesrc/color.out > ./results/color.txt;
DIFF=$(diff ./baseline/color_out.txt ./results/color.txt)

if [ "$DIFF" != "" ]
then
    printf "Colors failed\n"
else
    printf "Colors Passed\n"
fi

rm ./testingfilesrc/color.out;
