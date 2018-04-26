#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

static int	extend(char *str, int nb)
{
	int len;
	int puissance;
	int result;

	result = 0;
	puissance = 1;
	len = 0;
	while (*str >= '0' && *str <= '9')
	{
		len++;
		str++;
	}
	str--;
	while (len > 0)
	{
		result += (*str - 48) * puissance;
		puissance *= 10;
		str--;
		len--;
	}
	if (nb == -1)
		return (-1 * result);
	else
		return (result);
}

int			ft_atoi(char *str)
{
	int nb;
	int continuer;

	continuer = 1;
	while (continuer == 1)
	{
		if ((str[0] >= 9 && str[0] <= 13) || str[0] == 32)
			str++;
		else if (str[0] == '+' && (str[1] >= '0' && str[1] <= '9'))
		{
			continuer = 0;
			str++;
		}
		else if (str[0] == '-' && (str[1] >= '0' && str[1] <= '9'))
		{
			nb = -1;
			str++;
			continuer = 0;
		}
		else if (str[0] >= '0' && str[0] <= '9')
			continuer = 0;
		else
			return (0);
	}
	return (extend(str, nb));
}


static void ft_putstr(char *message)
{
    write(2, message, strlen(message));
}

void *malloc(size_t size)
{
    char *stop_after;
    int value;
    static int nb_malloc = 0;

    ft_putstr("malloc\n");
    stop_after = getenv("NB_MALLOC");
    if (!stop_after)
    {
        ft_putstr("No env variable\n");
        exit(0);
    }
    ft_putstr(stop_after);
    value = atoi(stop_after);
    if (nb_malloc == value)
        return (NULL);
    else        
        return mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
}