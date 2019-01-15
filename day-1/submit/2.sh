#!/bin/bash

awk '{for(i = 1; i <= NF; i++) {a[$i]++}} END {for(k in a) if(a[k] == 1){counter++} print "Unique words are: "counter}' welcome.txt

awk '{for(i = 1; i <= NF; i++) {a[$i]++}} END {for(k in a) if(a[k] > max){
max = a[k]
word = k
} print "Maximum occured word in file: "word}' welcome.txt
