#/bin/sh
BASEDIR=$(dirname "$0")
make -C $BASEDIR/src/libft/
gcc $BASEDIR/src/update_binary.c $BASEDIR/src/libft/libftprintf.a -o $BASEDIR/binary/update_binary
gcc $BASEDIR/src/malloc.c -shared -fPIC -o $BASEDIR/binary/malloc

find $1 -type f -name '*.o' -exec ./$BASEDIR/binary/update_binary '{}' \;
gcc `find $1 -type f -name '*.o'` $BASEDIR/src/malloc.c -o $BASEDIR/segfaulted
export NB_MALLOC=$3
valgrind ./$BASEDIR/segfaulted $2
