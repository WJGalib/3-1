#!/bin/bash
input1=$1
input2=$2
input3=$3

yacc -d -Wcounterexamples -Wother -Wconflicts-sr 1905084.y
echo 'Generated the parser C file as well the header file'
g++ -w -c -o y.o y.tab.c
echo 'Generated the parser object file'
flex 1905084.l
echo 'Generated the scanner C file'
g++ -w -c -o l.o lex.yy.c
# if the above command doesn't work try g++ -fpermissive -w -c -o l.o lex.yy.c
echo 'Generated the scanner object file'
g++ y.o l.o -lfl -o 1905084
echo 'All ready, running'
./1905084 "inputs/${input1}.c" "outputs/${input1}_parsetree.txt" "outputs/${input1}_error.txt" "outputs/${input1}_log.txt"
./1905084 "inputs/${input2}.c" "outputs/${input2}_parsetree.txt" "outputs/${input2}_error.txt" "outputs/${input2}_log.txt"
./1905084 "inputs/${input3}.c" "outputs/${input3}_parsetree.txt" "outputs/${input3}_error.txt" "outputs/${input3}_log.txt"

