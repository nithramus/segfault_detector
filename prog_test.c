#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *ptr;

    malloc(5);
    ptr = NULL;
    ptr[0] = 1;
    return 0;
}