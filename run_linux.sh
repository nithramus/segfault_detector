#!/bin/sh 
export LD_PRELOAD=/home/nithramir/C/segfault_detector/malloc
export NB_MALLOC=$1
valgrind ./$2
