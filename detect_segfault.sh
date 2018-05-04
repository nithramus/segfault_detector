#/bin/sh
make -C src/libft/
gcc src/update_binary.c src/libft/libftprintf.a -o binary/update_binary
gcc src/malloc.c -shared -fPIC -o binary/malloc


#trap 'ls -a' 11
filename='binary/test_file'

cp $1 $filename
./binary/update_binary $filename

#export LD_PRELOAD=/home/nithramir/C/segfault_detector/malloc
export DYLD_LIBRARY_PATH=./binary
export DYLD_INSERT_LIBRARIES="binary/malloc" 
export DYLD_FORCE_FLAT_NAMESPACE=1
for i in `seq 0 $3`;
do
    echo $i
    export NB_MALLOC=$i
	rm -f yolo
    ./$filename $2 >> sortie
done
