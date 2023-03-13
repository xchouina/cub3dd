#include "cub3d.h"

void	check_few_arg(t_game *game)
{
	if (game->dir_NO > 1 || game->dir_SO > 1 || game->dir_WE > 1\
	 || game->dir_EA > 1 || game->dir_F > 1 || game->dir_C > 1)
	{
		game->checker = 1;
		dprintf(2, "too many arguments\n");
		ft_quit(game);
	}
	if (game->dir_NO < 1 || game->dir_SO < 1 || game->dir_WE < 1\
	 || game->dir_EA < 1 || game->dir_F < 1 || game->dir_C < 1)
	{
		game->checker = 1;
		dprintf(2, "too few argument\n");
		ft_quit(game);
	}
}

void	fd_null(t_game *game)
{
	dprintf(2, "fd = NULL\n");
	ft_quit(game);
}

void	check_after_comma(t_game *game, int i, int j)
{
	if (ft_isdigit(game->textures_tab[i][j + 1]) == 0)
	{
		dprintf(2, "rgb error\n");
		ft_quit(game);
	}
}

void	comma_check(int comma, t_game *game)
{
	if (comma != 2)
	{
		dprintf(2, "rgb error comma\n");
		ft_quit(game);
	}
}

void	check_comma(t_game *game)
{
	int	j;
	int	i;
	int	comma;

	j = 0;
	i = 4;
	comma = 0;
	while (i < 6)
	{
		while (game->textures_tab[i][j] != '\0')
		{
			if (game->textures_tab[i][j] == ',')
			{
				check_after_comma(game, i, j);
				comma++;
			}
			j++;
		}
		comma_check(comma, game);
		i++;
		j= 0;
		comma = 0;
	}
}
