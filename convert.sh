#!/bin/bash

#Log file location
log="/var/log/psicekicad.log"

echo "###########Start Conversion from PSPICE to KICAD#################" >> $log
echo "" >>$log
echo "The Conversion starts at `date`" >> $log
####Getting Parameter
convertedSchematic=$1 
filepath=$2 
username=$3 
cwd=`pwd`

echo "">>$log
echo "The paramters to the script is : ">>$log
echo "File : $filepath">>$log
echo "Username : $username">>$log
filename=`basename $filepath`
filewithoutExt="${filename%.*}"

echo "File name is : $filename">>$log
echo "File name without extension : $filewithoutExt">>$log
echo "">>$log

#Create Directory for every User

if [ -d $convertedSchematic/$username ];then
    echo "User directory $username is already available">>$log
else
    mkdir -p $convertedSchematic/$username
fi

echo "The converted file will be present at $convertedSchematic/$username">>$log

#Creating directory for uploaded Project
mkdir -p $convertedSchematic/$username/$filewithoutExt

#Converting PSpice to Kicad Schematic
echo "Calling Schematic conversion script" >>$log
/var/www/html/esim_in/sites/all/modules/pspice_to_kicad/schConverter64 $filepath $convertedSchematic/$username/$filewithoutExt/$filename 2>&1>>$log

#Converting to Zip file
cd $convertedSchematic/$username
#sudo zip -rq -rm $zipname $filewithoutExt
echo "Creating zip file of converted project">>$log
zip -r $filewithoutExt{.zip,} 2>&1>>$log
echo "The zip file is present at `pwd`">>$log
cd $cwd
rm -rf $convertedSchematic/$username/$filewithoutExt

echo "###########End PSICE to KICAD Conversion#########################">>$log
echo " ">>$log

exit

