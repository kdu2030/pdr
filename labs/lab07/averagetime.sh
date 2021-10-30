#Name: Kevin Du
#Date: 10/28/2021
#ID: kd5eyn
#Filename: averagetime.sh

#!/bin/bash

#gets input from the user
echo "enter the exponent for counter.cpp:"
read iter

#need $ before variable name, space between ==, and [[]] for it to work
if [[ "$iter" == "quit" ]]; then
	#Exit the program with exit code 0
	echo "Exiting"
	exit 0
fi


sum=0

#Run this 5 times
for i in {1..5}; do
	echo "Running iteration ${i}..."
	run=`./a.out ${iter}`
	echo "time taken: ${run} ms" 
	(( sum += run ))
done

echo "5 iterations took ${sum} ms"
#Create a new variable named average, assign the value to be sum/5
(( avg=${sum}/5 ))
echo "Average time: ${avg} ms"
