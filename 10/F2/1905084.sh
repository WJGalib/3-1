#! /bin/bash
input=$1
flex -o lex.yy.c 1905084.l && g++ -std=gnu++17 lex.yy.c -o lex.yy && ./lex.yy "$input"