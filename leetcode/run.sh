#! /bin/bash
# author Jie Huang
# 1/10/24
# compile and run c++ and java files

FILE="RemoveNthNodeFromEndOfList"
# FILE=`date +%b%d`
# COUNT=10
# NUM=0

clear

# C++
g++ $FILE.cpp -o $FILE -std=c++11 -w
# g++ $FILE.cpp -o $FILE -std=c++11
# ./$FILE 1000000
./$FILE
# ./$FILE < $FILE-test-case-$NUM.txt
# ./$FILE < $rand-$COUNT.txt
# ./$FILE < ../includes/rand-$COUNT.txt
# ./$FILE < ../resources/rand-$COUNT.txt
# g++ Main.cpp -o Main -std=c++11
# ./Main

# JAVA
# javac $FILE.java
# java $FILE
