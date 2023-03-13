
#include "cub3d.h"

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

int find_first_line(int i, t_game *game)
{
	int j;

	j = 0;
	while (!ft_strchr(game->map[i], 'Q'))
		i++;
	return (i - 1);
}

void	fill_square_map(int k, int i, int j, t_game *game)
{
	game->square_map[k] = ft_calloc(game->max_line, sizeof(char));
	while (j < (game->max_line - 1))
	{
		if (game->map[i][j] == ' ' || game->map[i][j] == '	' || game->map[i][j] == '0' \
		|| game->map[i][j] == '\n' || game->map[i][j] == '1' || game->map[i][j] == '\0')
			game->square_map[k][j] = '1';
		else if (game->map[i][j] == 'Q')
			game->square_map[k][j] = 'Q';
		else
			game->square_map[k][j] = '1';
		if(game->map[i][j] == '\n')
		{
			while (j < (game->max_line - 1))
			{
				game->square_map[k][j] = '1';
				j++;
			}
		}
		j++;
	}
	game->square_map[k][j] = '\n';
}

void	square_map(t_game *game)
{
	int i;
	int j;
	int	k;

	i = 0;
	j = 0;
	k = -1;
	while (i < game->map_height)
	{
		find_max_line(i, game);
		if (!ft_strchr(game->map[i], 'Q') && game->check_first_Q == 1)
			break;
		i++;
	}
	game->height_Q = i + 1;
	i = 0;
	i = find_first_line(i, game);
	// i = i - 1;
	max_map(game);
	game->max_line += 3;
	game->square_map = ft_calloc(game->height_Q + 2, sizeof(char *));
	while (i < game->height_Q)
	{
		fill_square_map(++k, i, j, game);
		i++;
	}
}
