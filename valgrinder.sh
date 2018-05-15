#/bin/sh
make -C src/libft/
gcc src/update_binary.c src/libft/libftprintf.a -o binary/update_binary
gcc src/malloc.c -shared -fPIC -o binary/malloc

find $1 -type f -name '*.o' -exec ./binary/update_binary '{}' \;
gcc `find $1 -type f -name '*.o'` src/malloc.c -o segfaulted
export NB_MALLOC=$3
valgrind ./segfaulted $2
