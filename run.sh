#!/bin/sh

gcc -Wall -Wextra -Werror ./main.c -o ./main.out
./main.out 006000 500070 000300 000000 890000 000200
/bin/rm ./main.out
