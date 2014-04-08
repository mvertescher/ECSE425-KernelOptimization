#!/bin/bash

largest=15000

for (( N = 100; N<=$largest; N+=100 )) do
	#echo "N = $N"
	./build/ecse425proj -operation 1 -N $N
	#echo " "
done