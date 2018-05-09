filename='../binary/test_file'

# export LD_PRELOAD=../binary/malloc
export DYLD_LIBRARY_PATH=../binary
export DYLD_INSERT_LIBRARIES="../binary/malloc" 
export DYLD_FORCE_FLAT_NAMESPACE=1
#
#echo $2
export NB_MALLOC=$2
valgrind ./$filename $1


# lldb $filename < run
#run $filename
