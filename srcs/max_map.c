
#include "cub3d.h"

void	max_map(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (game->square_map[i] != NULL)
	{
		j = 0;
		while (game->square_map[i][j] != '\n')
		{
			j++;
			if (j > 30)
			{
				printf("Map to big");
				ft_quit(game);
			}
		}
		i++;
		if (i > 20)
		{
				printf("Map to big");
				ft_quit(game);
		}
	}
}