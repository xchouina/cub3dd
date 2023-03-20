#include "cub3d.h"

void	check_map(t_game *game)
{
	check_symbol_and_doublon(game);
	if (game->doublons == 0)
	{
		dprintf(2, "No player on map\n");
		ft_quit(game);
		// game->checker = 1;
		// return ;
	}
	floodfill(game->player.player_mm.position_y, game->player.player_mm.position_x, game);
}

void	check_symbol_and_doublon(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (ft_strchr("01 NSEW\n", game->map[i][j]) != NULL)
			{
				check_end_line(game, i, j);
				// if (game->checker == 1)
				// 	return ;
				j++;
			}
			else
			{
				// game->checker = 1;
				dprintf(2, "%c = symbol error\n", game->map[i][j]);
				ft_quit(game);
				// return ;
			}
		}
		i++;
	}
}

void	check_end_line(t_game *game, int i, int j)
{
	if (game->map[i][j] == '\n' && ft_strlen(game->map[i]) == 1)
	{
		dprintf(2, "Backslash_n needs to be at the end of the line\n");
		ft_quit(game);
		// game->checker = 1;
		// return ;
	}
	if (game->map[i][j] == 'W' || game->map[i][j] == 'E'\
	 || game->map[i][j] == 'S' || game->map[i][j] == 'N')
	{
		game->player.player_mm.position_x = j;
		game->player.player_mm.position_y = i;

		if (game->doublons != 0)
		{
			dprintf(2, "too many players on map\n");
			ft_quit(game);
			// game->checker = 1;
			// return ;
		}
		else
			game->doublons = 1;
	}
}

void	outside_map(t_game *game)
{
	dprintf(2, "you are outside of the map\n");
	ft_quit(game);
}

void	floodfill(int x, int y, t_game *game)
{
	if (game->map[x][y] < 37)
	{
		dprintf(2, "map not closed\n");
		ft_quit(game);
		// game->checker = 1;
		// return ;
	}
	if (game->map[x][y] == '0' || game->map[x][y] == 'N' ||\
	game->map[x][y] == 'E' || game->map[x][y] == 'W' || game->map[x][y] == 'S')
	{
		if (x <= 0 || y <= 0)
			outside_map(game);
		if (game->map[x][y] == 'N' || game->map[x][y] == 'E' \
		|| game->map[x][y] == 'W' || game->map[x][y] == 'S')
			game->player.carddir = game->map[x][y];
		game->map[x][y] = 'Q';
	}
	else
		return ;
	//print_floodfill(game);
	floodfill(x - 1, y, game);
	floodfill(x, y + 1, game);
	floodfill(x + 1, y, game);
	floodfill(x, y - 1, game);
}

void	print_floodfill(t_game *game)
{
	int	i;

	i = 0;
	usleep(100000);
	printf("\e[1;1H\e[2J");
	while (game->map[i])
	{
		printf("%s\n", game->map[i]);
		i++;
	}
}
