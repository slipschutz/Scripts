#!/bin/bash


NO_ARGS=0;

if [ $# -ne 2 ] ;  # Script invoked with no command-line arguments
then
  echo "Usage: ./`basename $0` runNumber ForkLevel"
  exit 1          # Exit and explain usage, if no argument(s) given.
fi  

runNumber=$1
ForkLevel=$2
dir=$(pwd)

cd /mnt/daqtesting/lenda/experiment/run${runNumber}
numFiles=$(ls | wc -l)
echo "Expecting $numFiles files for this run"

#numFiles=1;
cd ~/analysis/run${runNumber}

total=$(root -b -q -l ../scripts/GetNumberEntries.C\($runNumber,$numFiles\))
total=$(echo $total | awk 'BEGIN{FS="qwer"} {print $2} ')
echo "total is " $total
echo "Fork level is " $ForkLevel


if [ $runNumber -ge 360 ]; then
    flag="false"
else
    flag="true"
fi

cd $dir

num=$(($total/$ForkLevel))
echo "integer events per fork " $num

for ((i=0;i<$ForkLevel;i++)) do

   Begin=$(($i*$num))
    
   if [ $i -eq $(($ForkLevel-1)) ]; then
       End=$total
   else 
       End=$(($(($i+1))*$num))
   fi
command="$(pwd)/GammaBuilder $runNumber startEntry:$Begin maxEntry:$End FL:3 fg:0 w:0 d:3 notes:Fork$i numFiles:$numFiles lean:true isOldFormat:${flag} sg2:9 timeWindow:35 minN:1"
#echo $command
SubmitSeaside.sh $command

done