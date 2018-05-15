#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

static void ft_putstr(char *message)
{
    write(2, message, strlen(message));
}
void *maloic(size_t size)
{

    char *stop_after;
    int value;
    static int nb_malloc = -1;

    nb_malloc++;
    stop_after = getenv("NB_MALLOC");
    if (!stop_after)
    {
        ft_putstr("No env variable\n");
        exit(0);
    }
    // ft_putstr(stop_after);
    value = atoi(stop_after);
    if (nb_malloc == value)
        return (NULL);
    else        
        return malloc(size);
}
