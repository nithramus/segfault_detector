#/bin/sh
BASEDIR=$(dirname "$0")
make -C $BASEDIR/src/libft/
gcc $BASEDIR/src/update_binary.c $BASEDIR/src/libft/libftprintf.a -o $BASEDIR/binary/update_binary
gcc $BASEDIR/src/malloc.c -shared -fPIC -o $BASEDIR/binary/malloc

filename='/binary/test_file'

cp $1 $BASEDIR/$filename
./$BASEDIR/binary/update_binary $BASEDIR/$filename

export DYLD_LIBRARY_PATH=./$BASEDIR/binary
export DYLD_INSERT_LIBRARIES="$BASEDIR/binary/malloc" 
export DYLD_FORCE_FLAT_NAMESPACE=1
	rm -f $BASEDIR/sortie
for i in `seq 0 $3`;
do
    echo $i
    export NB_MALLOC=$i
    ./$BASEDIR/$filename $2 >> $BASEDIR/sortie
done
