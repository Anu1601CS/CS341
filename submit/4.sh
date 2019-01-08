#!/bin/bash
# Register color
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;35m'
BLUE='\033[0;34m'
NC='\033[0m'

declare -a arr
i=0

for fname in OS/*.txt ; do
_file="$fname"

    if [ -s "$_file" ]
then
    line=$(head -n 1 $fname)
    filesize=$(stat -c%s "$fname")

arr[$filesize]="$line"
map[$i]="$filesize"
i=`expr $i + 1`

else

    emptyFile=$_file

    fi
    done

    if [ -s $emptyFile ]
        then
        printf "${RED}No Empty file found.\nFailed.${NC}"
        else
        printf "${RED}Empty file: ${NC}${emptyFile}\n"
        printf "${BLUE} Writing data to file ${NC} \n"

    for ((i=0; i<4; i++))
        do
            for((j=i; j<4-i-1; j++))
                do
                if ((${map[j]} < ${map[$((j+1))]}))
                    then
                    temp=${map[$j]}
                    map[$j]=${map[$((j+1))]}
                    k=`expr $j + 1`
                    map[$k]=$temp
                fi
            done
        done

        for ((i=3;i>=0;i--))
        do
            fn=${map[$i]}
            echo ${arr[$fn]}>>$emptyFile
        done

        printf "${GREEN}Done!${NC}"

    fi
