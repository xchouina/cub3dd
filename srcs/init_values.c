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
	game->max_line = 0;
	game->check_last_Q = 0;
	game->check_first_Q = 0;
}

int find_max_line(int i, t_game *game)
{
	int j;

	j = 0;
	while (game->map[i][j] != '\0')
	{
		if (game->map[i][j] == 'Q')
			game->check_first_Q = 1;
		if (game->map[i][j] == 'Q' && j > game->max_line)
			game->max_line = j;
		j++;
	}
	j = 0;
	return (i);
}

void	max_map(t_game *game)
{
	//printf("max height = %d", game->map_height);
	if (game->height_Q + 1 > 20 || game->max_line > 30)
	{
		printf("map too big");
		ft_quit(game);
	}
}

void	square_map(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < game->map_height)
	{
		find_max_line(i, game);
		if (!ft_strchr(game->map[i], 'Q') && game->check_first_Q == 1)
			break;
		i++;
	}
	game->height_Q = i + 1;
	i = 0;
	max_map(game);
	game->max_line += 3;
	game->square_map = ft_calloc(game->height_Q + 2, sizeof(char *));
	while (i < game->height_Q)
	{
		fill_square_map(i, j, game);
		i++;
	}
}

void	fill_square_map(int i, int j, t_game *game)
{
	game->square_map[i] = ft_calloc(game->max_line, sizeof(char));
	while (j < (game->max_line - 1))
	{
		if (game->map[i][j] == ' ' || game->map[i][j] == '	' || game->map[i][j] == '0' \
		|| game->map[i][j] == '\n' || game->map[i][j] == '1' || game->map[i][j] == '\0')
			game->square_map[i][j] = '1';
		else if (game->map[i][j] == 'Q')
			game->square_map[i][j] = 'Q';
		else
			game->square_map[i][j] = '1';
		j++;
	}
	game->square_map[i][j] = '\n';
}
