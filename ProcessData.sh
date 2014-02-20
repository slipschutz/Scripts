#!/bin/bash

NO_ARGS=0;

if [ $# -eq "$NO_ARGS" ] || [ $# -eq 1 ]  # Script invoked with no command-line args?
then
  echo "Usage: ./`basename $0` -r run_number options(dbmf)"
  exit 1          # Exit and explain usage, if no argument(s) given.
fi  
# Usage: scriptname -options
# Note: dash (-) necessary

doDDASdump=0;
runNum=0;
build=0;
mail=0;
ForkLevel=1;
Fail=0;
OnlyLA=0;
while getopts ":dr:bmf:L" Option
do
  case $Option in
    d     ) doDDASdump=1;;
    r     ) runNum=$OPTARG;;
    b     ) build=1;;
    m     ) mail=1;;
    f     ) ForkLevel=$OPTARG;;
    L     ) OnlyLA=1;;
    *     ) Fail=1;;
  esac
done
if [ $Fail -eq 1 ]; then
    echo "Unimplemented option chosen.";
    exit;
fi

shift $(($OPTIND - 1))

if [ ${doDDASdump} -eq 1 ] && [ `whoami` != "cedaq" ]; then
echo "Error:"
echo "ssh to daq machine as cedaq to run dumper ";
exit;
fi

################Where everything is########################
top_dir='/mnt/daqtesting/lenda/sam_analysis'
path_evt='/mnt/daqtesting/lenda/experiment/run'${runNum}
path_root='/mnt/daqtesting/lenda/rootfiles/'
path_analysis='/mnt/daqtesting/lenda/sam_analysis'

loc=$top_dir

cd $path_evt
num=`ls | wc -l`

dumper_start=`date`;
if [ $doDDASdump -eq 1 ]; then 
    cd /user/cedaq/neutron/DDAS/ddasdumper ## CHANGE to the location of ddasDumper
    
    for ((i=0;i<$num;i++)); do
	
	if [ $i -lt 10 ]; then
	    echo 
	    ./ddasdumper --source=file://${path_evt}/run-0${runNum}-0${i}.evt --fileout=${path_root}/run-0${runNum}-0${i}.root
	fi
	
	if [ $i -ge 10 ]; then
	    echo
	    ./ddasdumper --source=file://${path_evt}/run-0${runNum}-${i}.evt --fileout=${path_root}/run-${runNum}-${i}.root
	fi
    done
fi
dumper_end=`date`;    


##script is run from sam_analysis directory
cd $loc

##check to see if there is a run${runNum} directory
if [ ! -d "./run${runNum}" ]; then
    echo "No run directory found.  Making new run directory";
    mkdir "./run${runNum}";
else 
    echo "run directory found";
fi
##Change to the Run Directory
cd ./run${runNum};
runDir=`pwd`;

cd ${runDir}

##check to see if all the raw root  files are in the run directory
allGood=1;

for ((i=0;i<$num;i++)); do 
    if [ $i -lt 10 ]; then
	file=run-0${runNum}-0${i}.root;
	if [ ! -f $file ];then
	    allGood=0;
	    break;
	fi
    fi
    
    if [ $i -ge 10 ]; then
	file=run-0${runNum}-${i}.root;
	if [ ! -f $file ];then
	    allGood=0;
	    break;
	fi
    fi

done
#############

if [ $allGood -eq 1 ]; then
    echo "All the root files have been linked"
elif [ $allGood -ne 1 ]; then 
    echo "Need to make links for the files"

    for ((i=0;i<$num;i++)); do
	if [ $i -lt 10 ]; then
	    file=run-0${runNum}-0${i}.root; ##Format in Root Directory From Dumper
	    file2=run-0${runNum}-0${i}.root; ##Format with run-0### always
        elif [ $i -ge 10 ];then
	    file=run-${runNum}-${i}.root; ##Format in Root Directory from Dumper
	    file2=run-0${runNum}-${i}.root; ##Format with run-0### always
	fi

	if [ -f /${path_root}/${file} ]  && [ ! -f /${runDir}/${file} ]; then
	    ##If the File is in the Root Directory but not in the rundirectory make sym link
	    echo "This file needs a link: " $file
	    echo "Linking..."
	    ln -s /${path_root}/${file} /${runDir}/${file2}
	fi
    done
fi
##make links for builders
cd ${runDir};

if [ ! -f GammaBuilder ]; then
    echo "Linking GammaBuilder"
    ln -s ../GammaBuilder/GammaBuilder
fi

build_start=`date`;
if [ $build -eq 1 ]; then 
    if [ ! -d "./Logs" ]; then
	mkdir "./Logs";
    fi
    mv *.o* ./Logs
    
    if [ $(uname -a | awk ' {print $2 } ') != "seaside" ]; then
	echo "SSH into seaside to run builder";
	exit;
    fi
    if [ $OnlyLA -eq 0 ]; then
	../scripts/ForkBuilder.sh ${runNum} ${ForkLevel}
        ##wait a little for the jobs to start
	sleep 15;
	loop=1;
	while [ $loop -eq 1 ]; do
	    numRunning=$(qstat -u `whoami` | grep `whoami` | awk ' {print $10}' | awk ' {if ($0~/R/){print}}' | wc -l);
	    echo "Number of Builders still Running $numRunning";
	    if [ $numRunning -eq 0 ]; then
		loop=0; ##Stop looping
	    else
		sleep 5;
	    fi
	done
    fi
    cd ${runDir}
   if [ ${OnlyLA} -eq 1 ]; then
       touch *fork*; ## to make sure that the right file type is found
   fi
   ###Now Run the ForkLendaAnalysis script
   ###Needs the file name from the GammaBuilder
    FileTemplate=$(ls -lhtr ${runDir} | grep run-0${runNum} | awk '{print $9}' | tail -1)
    echo "FileTemplate is" $FileTemplate
    ../scripts/ForkLendaAnalysis.sh ${runNum} ${FileTemplate} ${ForkLevel}
    ##wait a little for the jobs to start
    sleep 15;
    loop=1;
    while [ $loop -eq 1 ]; do
	numRunning=$(qstat -u `whoami` | grep `whoami` | awk ' {print $10}' | awk ' {if ($0~/R/ || $0~/Q/){print}}' | wc -l);
	echo "Number of LendaAnalyses still Running $numRunning";
	if [ $numRunning -eq 0 ]; then
	    loop=0; ##Stop looping
	else
	    sleep 5;
	fi
    done
    ### Now Run the Merger
    ~/LendaMerger/LendaMerger ${runNum} numFiles:${ForkLevel}
fi

build_end=`date`;

if [ ! -d "./Logs" ]; then
    mkdir "./Logs";
fi
mv *.o* ./Logs





dump_time=$((`date "+%s" -d "${dumper_end}"` - `date "+%s" -d "${dumper_start}"`)) ;
build_time=$((`date "+%s" -d "${build_end}"` - `date "+%s" -d "${build_start}"`)) ;




echo;echo;
summary="Run ${runNum} was processed. Build command was:\n ${command}\n";
summary="${summary}the options were:\n";
summary="${summary}doDDASdumper ${doDDASdump}\n"
summary="${summary}build ${build}\n"
summary="${summary}\nTime elapsed for the dumper was ${dump_time} seconds";
summary="${summary}\nTime elapsed for the builder was ${build_time} seconds\n";
summary="${summary}\n Fork Level was ${ForkLevel}\n";
summary="${summary}\n QWER Level ${ForkLevel} Time ${build_time}\n"


if [ $mail -eq 1 ]; then
    subject="Run_${runNum}_on_`date "+%d_%m_%y_%H_%M_%S"`";
    echo -e $summary | mail -s ${subject} soam5515@yahoo.com
fi 

echo -e $summary;





