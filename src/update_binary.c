#include "libft/libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

size_t	ft_strnnstr(const char *str, const char *substring, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (i < len)
	{
		while (str[i + j] == substring[j] && (i + j < len))
		{
			j++;
			if (substring[j] == '\0')
				return i;
		}
		j = 0;
		i++;
	}
	return (0);
}


int main(int argc, char **argv)
{
     struct stat buf;
     char *file;

    if (argc < 2)
    {
        ft_putendl("no input file");
        return 0;
    }
    int fd = open(argv[1], O_RDWR);
    if (!fd)
    {
        ft_putendl("wrong file");
        return 0;
    }
    if (fstat(fd, &buf) != 0)
    {
        perror("fstat: ");
        return 0;
    }
    // ft_printf("%zu\n", buf.st_size);
    file = malloc(buf.st_size);
    int value = read(fd, file, buf.st_size);
    // ft_putnbr(value);
    if (value != buf.st_size)
    {
        perror("Read:");
        return 0;
    }
    size_t ptr = ft_strnnstr(file, "malloc\0", buf.st_size);
    // ft_printf("%zu\n", ptr);
    lseek(fd, (off_t)ptr, SEEK_SET);
    write(fd, "maloic\0", 7);
    return 0;
}