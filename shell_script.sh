#/bin/sh

#trap 'ls -a' 11
filename='test_file'

cp $1 $filename
./update_binary $filename

export LD_PRELOAD=/home/nithramir/C/segfault_detector/malloc
for i in `seq 0 10`;
do
    echo $i
    export NB_MALLOC=$i
    ./$filename > yolo
done