#!/bin/bash

# Secure copy the .dat files on the server

# Get the D1 cache size sweep
#sudo scp matthew.vertescher@tr5130gu-2:~/ECSE425-KernelOptimization/build/D1_CACHESIZE.dat ./dats

# Get the I1 cache size sweep
#sudo scp matthew.vertescher@tr5130gu-2:~/ECSE425-KernelOptimization/build/I1_CACHESIZE.dat ./dats

# Get the LL cache size sweep
#sudo scp matthew.vertescher@tr5130gu-2:~/ECSE425-KernelOptimization/build/LL_CACHESIZE.dat ./dats

sudo scp matthew.vertescher@tr5130gu-2:~/ECSE425-KernelOptimization/build/D1_BLOCKSIZE.dat ./dats
sudo scp matthew.vertescher@tr5130gu-2:~/ECSE425-KernelOptimization/build/I1_BLOCKSIZE.dat ./dats
sudo scp matthew.vertescher@tr5130gu-2:~/ECSE425-KernelOptimization/build/LL_BLOCKSIZE.dat ./dats

sudo scp matthew.vertescher@tr5130gu-2:~/ECSE425-KernelOptimization/build/D1_ASSOCIATIVITY.dat ./dats
sudo scp matthew.vertescher@tr5130gu-2:~/ECSE425-KernelOptimization/build/I1_ASSOCIATIVITY.dat ./dats
sudo scp matthew.vertescher@tr5130gu-2:~/ECSE425-KernelOptimization/build/LL_ASSOCIATIVITY.dat ./dats