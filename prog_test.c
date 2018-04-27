#include <string.h>
#include <stdlib.h>

 int main(int argc, char **argv)
{
    // char *ptr;
    char *ptr = malloc(5);
    
    ptr[0] = 't';

    ptr = malloc(5);
    
    ptr[0] = 't';
    write(1,"yolo\n", 5);   
    // ptr = NULL;
    // ptr[0] = 1;
    // return 0;
}