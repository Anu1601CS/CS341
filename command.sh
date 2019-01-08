#!/bin/bash

# Command line helper
my_dir="$(dirname "$0")"

# Register color
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;35m'
BLUE='\033[0;34m'
NC='\033[0m'

export RED GREEN YELLOW BLUE NC

printf "${RED}==========================================${NC}\n"
printf "${GREEN}CS341 Lab 1${NC}\n"
printf "${RED}==========================================${NC}\n"

printf "${BLUE}Please select question no.${NC}\n"
printf "\n"

echo "1 -> Question 1."
echo "2 -> Question 2."
echo "3 -> Question 3."
echo "4 -> Question 4."

while :
do
  printf "\n"
  read -p "-> " INPUT_STRING

  case $INPUT_STRING in
	1)
    printf "${RED}A)${NC}${BLUE} How many CPU and cores does the machine have?${NC}\n"
    printf "${GREEN}Answer: ${NC}\n"

    printf "${GREEN}Command Used: cat /proc/cpuinfo | grep processor | wc -l && grep ^cpu\\scores /proc/cpuinfo | uniq |  awk '{print \$4}'\n"
    printf "${BLUE}CPU: "
    cat /proc/cpuinfo | grep processor | wc -l

    printf "${BLUE}CPU CORES: "
    grep ^cpu\\scores /proc/cpuinfo | uniq |  awk '{print $4}'

    printf "${NC}\n"

    printf "${RED}B)${NC}${BLUE} What is the frequency of each CPU ?${NC}\n"
    printf "${GREEN}Answer: ${NC}\n"

    printf "${GREEN}Command Used: cat /proc/cpuinfo | grep \"^[c]pu MHz\" \n"
    printf "${BLUE}"
    cat /proc/cpuinfo | grep "^[c]pu MHz"
    printf "${NC}\n"

    printf "${RED}C)${NC}${BLUE} How much memory does your system have?${NC}\n"
    printf "${GREEN}Answer: ${NC}\n"

    printf "${GREEN}Command Used: cat /proc/meminfo | grep -m 1 MemTotal \n"
    printf "${BLUE}"
    cat /proc/meminfo | grep -m 1 MemTotal
    printf "${NC}\n"

    printf "${RED}D)${NC}${BLUE} How much of it is free and available? What is the difference between them?${NC}\n"
    printf "${GREEN}Answer: ${NC}\n"

    printf "${GREEN}Command Used: cat /proc/meminfo | grep -m 1 MemFree && cat /proc/meminfo | grep -m 1 MemAvailable\n"
    printf "${BLUE}"
    cat /proc/meminfo | grep -m 1 MemFree
    cat /proc/meminfo | grep -m 1 MemAvailable
    printf "${NC}\n"

    printf "${RED}E)${NC}${BLUE} What is total number of user-level processes in the system?${NC}\n"
    printf "${GREEN}Answer: ${NC}\n"

    printf "${GREEN}Command Used: ps hax -o user | sort | uniq -c \n"
    printf "${BLUE}"
    ps -u "$(echo $(printf '%s\n' $(users) | sort -u))" o user= | sort | uniq -c | sort -rn
    # cat /proc/PID/limits
    ps hax -o user | sort | uniq -c
    printf "${NC}"
    ;;

	2)

    printf "${RED}A.)${NC} ${BLUE}The number of unique words in the file. ${NC}\n"
    printf "${GREEN}Answer: ${NC}\n"

    printf "${BLUE}"
    awk '{for(i = 1; i <= NF; i++) {a[$i]++}} END {for(k in a) if(a[k] == 1){counter++} print "Unique words are: "counter}' welcome.txt
    printf "${NC}\n"

    printf "${RED}B.)${NC}${BLUE} The word which is present for maximum number of times in the file.  ${NC}\n"
    printf "${GREEN}Answer: ${NC}\n"

    printf "${BLUE}"
    awk '{for(i = 1; i <= NF; i++) {a[$i]++}} END {for(k in a) if(a[k] > max){
    max = a[k]
    word = k
    } print "Maximum occured word in file: "word}' welcome.txt
    printf "${NC}\n"
    ;;
  3)
		printf "${RED}Question: ${NC}${GREEN}Suppose you have a fibonacci sequence of length n, where n is a positive integer and
multiple of 3. Now you decide to cut down the sequence in three equal segments and do
an element-wise sum of the first and third segments. Finally, you concatenate the second
segment to the summed segment. Write a program in shell script to represent these
procedures. Display the results after each step. ${YELLOW}\n\n"

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
    ;;
  4)

	printf "${RED}Question: ${NC}${GREEN}A folder named OS contains four non-empty and one empty text files. Each of the
non-empty files contains different number of sentences. Write a program in shell script to
copy the first sentence from each non-empty file to the empty file. The sentences should
be placed based on the ascending order of the size of the non-empty files. ${YELLOW}\n\n"
printf "${GREEN}Answer: ${NC}\n"

    declare -a arr

	for fname in OS/*.txt ; do
  	_file="$fname"

		if [ -s "$_file" ]
  	then
		line=$(head -n 1 $fname)
    	filesize=$(stat -c%s "$fname")

	arr[$filesize]="$filesize $line"

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

			for key in ${!arr[@]}; do
				echo ${arr[${key}]}>>$emptyFile
			done

            sort $emptyFile

			printf "${GREEN}Done!${NC}"

		fi
		;;

		*)
    echo "Command Not found."
    ;;
  esac
done
echo
echo "Thanks."
