#!/bin/bash 
for ((j=0;j<10;j++)); do
for ((i=7;i<10;i++)); do

num=$(($i*5+40));
../scripts/ProcessData.sh -r 381  -b -f $num 

done
done