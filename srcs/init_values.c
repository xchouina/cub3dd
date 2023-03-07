#include "cub3d.h"

void	init_value(t_game *game)
{
	game->checker = 0;
	game->dir_NO = 0;
	game->dir_SO = 0;
	game->dir_WE = 0;
	game->dir_EA = 0;
	game->dir_F = 0;
	game->dir_C = 0;
	game->doublons = 0;
	game->direction_complete = 0;
	game->square_map = NULL;
	game->tab_fd = NULL;
	game->map = NULL;
	game->textures_tab = NULL;
	game->image = 0;
	game->a_is_press = 0;
	game->d_is_press = 0;
}

void	square_map(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	game->max_line = ft_strlen(game->map[i]);
	i++;
	while (i < game->map_height)
	{
		if ((int)ft_strlen(game->map[i]) > game->max_line)
			game->max_line = ft_strlen(game->map[i]);
		i++;
	}
	i = 0;
	game->square_map = ft_calloc(game->map_height, sizeof(char *));
	while (i < game->map_height)
	{
		fill_square_map(i, j, game);
		i++;
	}
}

void	fill_square_map(int i, int j, t_game *game)
{
	if ((int)ft_strlen(game->map[i]) < game->max_line)
	{
		game->square_map[i] = ft_calloc(game->max_line + 1, sizeof(char));
		while (game->map[i][j] != '\n')
		{
			game->square_map[i][j] = game->map[i][j]; 
			j++;
		}
		while (j < game->max_line)
		{
			game->square_map[i][j] = '1';
			j++;
		}
		game->square_map[i][j] = '\n';
	}
	else
	{
		game->square_map[i] = ft_strdup(game->map[i]);
	}
}
