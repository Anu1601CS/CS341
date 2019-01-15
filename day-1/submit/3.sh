#!/bin/bash
# Register color
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;35m'
BLUE='\033[0;34m'
NC='\033[0m'

read -p "Enter n multiple of 3 :-> " NUM
printf "${NC}"

declare -a array_main
declare -a array_sum

printf "Enter sequence: \n"

for(( c = 0 ; c < $NUM ; c++))
do
    read number
    array_main[$c]="$number"
done

sum=0

for(( c = 0 ; c < $NUM/3 ; c++))
do
    sum=$(( ${array_main[$c]}+${array_main[$num -1 -$c]} ))
    array_main[$c]="$sum"
done

printf "${GREEN}\nAnswer:\n${BLUE}"
for(( c = 0 ; c < 2*$NUM/3 ; c++))
do
    printf "${array_main[$c]} "
done
printf "${NC}\n"
