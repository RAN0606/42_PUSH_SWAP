#!/bin/bash
make
while true
do 
	ARG=../Random-numbers-generator/a.out $1 -9999 9999
    echo $ARG
    #./push_swap $ARG
    ./push_swap $ARG | wc -l
    ./push_swap $ARG | ./../checker_Mac $ARG
    #echo $ARG
    sleep 1
done
