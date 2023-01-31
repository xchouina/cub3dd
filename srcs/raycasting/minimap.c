#include "cub3d.h"

void	put_img(t_game *game, int x, int y)
{
	void	*mlx;
	void	*window;
	// dprintf(2, "here\n");
	mlx = game->mlx;
	window = game->window;
	if (game->map[y][x] == '1' || game->map[y][x] == '0')
		mlx_put_image_to_window(mlx, window, game->wall_mm, (25 * x), (25 * y));
	else if (game->map[y][x] == 'Q')
		mlx_put_image_to_window(mlx, window, game->ground_mm, (25 * x), (25 * y));
	// else if (game->map[y][x] == '\n')
	// 	dprintf(2, "%c\n", game->map[y][x]);
	mlx_put_image_to_window(game->mlx, game->window, game->player_mm, (25 * game->player.position_y), (25 * game->player.position_x));

	// 	dprintf(2, "NOT SUPPOSED TO PRINT: %d\n", game->map[y][x]);
}

void	map_creation(t_game *game)
{
	int	y;
	int	x;
	y = 0;
	x = 0;
	// dprintf(2, "%d = width\n", game->map_x);
	// dprintf(2, "%d = height\n", game->map_y);
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\n')
		{
			if (game->map[y][x] == '\0')
				break ;
			put_img(game, x, y);
			x++;
		}
		y++;
	}
}
