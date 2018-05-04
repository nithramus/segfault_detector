filename='test_file'

cp $1 $filename
./update_binary $filename

#export LD_PRELOAD=/home/nithramir/C/segfault_detector/malloc
#export DYLD_LIBRARY_PATH=.
#export DYLD_INSERT_LIBRARIES="malloc" 
#export DYLD_FORCE_FLAT_NAMESPACE=1
#
#echo $2
#export NB_MALLOC=$2
##valgrind ./$filename -R ~ > yolo


lldb $filename < run
#run $filename
