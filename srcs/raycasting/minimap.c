#include "cub3d.h"

void	put_img(t_game *game, int x, int y)
{
	void	*mlx;
	void	*window;
	// dprintf(2, "here\n");
	mlx = game->mlx;
	window = game->window;
	if (game->map[y][x] == '1' || game->map[y][x] == '0')
		// put_cube(game, x, y, game->textures.couleur_floor);
		mlx_image_to_window(mlx, game->wall.img, (25 * x), (25 * y));
	else if (game->map[y][x] == 'Q')
		// put_cube(game, x, y, game->textures.couleur_floor);
		mlx_image_to_window(mlx, game->ground.img, (25 * x), (25 * y));
	// else if (game->map[y][x] == '\n')
	// 	dprintf(2, "%c\n", game->map[y][x]);
	// game->instance->player_pos_y = game->pos.position_y;
	// game->instance->player_pos_x = game->pos.position_x;
	// (game->mlx, game->sprite_player.img, (25 * game->player.player_mm.position_x), (25 * game->player.player_mm.position_y));
	//put_player_on_mini_map(game);
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
			// put_cube(game, x, y);
			put_img(game, x, y);
			x++;
		}
		y++;
	}
}
