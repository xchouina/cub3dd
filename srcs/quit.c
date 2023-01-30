#include "cub3d.h"

void	ft_quit(int fd)
{
	close(fd);
	ft_putstr_fd("Map invalid\n", 2);
	exit(0);
}
