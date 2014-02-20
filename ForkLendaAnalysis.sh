#!/bin/bash


NO_ARGS=0;

if [ $# -ne 3 ] ;  # Script invoked with no command-line arguments
then
  echo "Usage: ./`basename $0` runNumber FileTemplate  Number Of Files"
  exit 1          # Exit and explain usage, if no argument(s) given.
fi  

runNumber=$1
FileName=$2
ForkLevel=$3



for ((i=0;i<$ForkLevel;i++)) do

    
command="/user/lipschut/LendaAnalysis/LendaAnalysis $runNumber inputFile:$FileName startFile:$i"
#echo $command
SubmitSeaside.sh $command

done