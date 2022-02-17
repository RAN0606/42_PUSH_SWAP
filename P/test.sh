#!/bin/bash
make
while true
do 
    ARG=$(./a.out 500 -9999 9999)
    #./push_swap $ARG
    ./push_swap $ARG | wc -l
    ./push_swap $ARG | ./../checker_Mac $ARG 
    #echo $ARG
    sleep 1
done
