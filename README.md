ECSE425-KernelOptimization
===========================

ECSE 425 course project using cachegrind to optimize square matrix multiplication.  

To run the program: 
1. $ ./COMPILE.sh 
2. $ ./build/ecse425proj


Log into trottier machines:
x : 1 - 15
ssh matthew.vertescher@tr5130gu-x
(use 2)

Copy data: 
sudo scp -r ECSE425-KernelOptimization matthew.vertescher@tr5130gu-2:~/


Remove all cachegrind output files:
rm -R cachegrind*

Processor info:
cat /proc/cpuinfo


Reference cache arch:
valgrind --tool=cachegrind --I1=32768,8,64 --D1=32768,8,64 --LL=6291456,24,64 ./ecse425proj -N 1000 -operation 1