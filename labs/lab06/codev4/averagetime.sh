#!/bin/bash

#gets input from the user, separated by spaces.
#First argument is saved into word, second argument is saved into grid.
read words grid

RUN1=`./a.out ${words} ${grid} | tail -1`
RUN2=`./a.out ${words} ${grid} | tail -1`
RUN3=`./a.out ${words} ${grid} | tail -1`
RUN4=`./a.out ${words} ${grid} | tail -1`
RUN5=`./a.out ${words} ${grid} | tail -1`

(( SUM=${RUN1}+${RUN2}+${RUN3}+${RUN4}+${RUN5} ))

echo $(( SUM/5 ))
