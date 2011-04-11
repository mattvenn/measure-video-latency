#!/bin/bash
for p in $*; do 
PID=`pidof $p`
for i in $PID; do #ionice is in /usr/src/linux/Documentation/block/ioprio.txt
sudo ionice -c1 -n7 -p $i
sudo renice -3 -p $i
sudo chrt -r -p 75 $i
done
done
