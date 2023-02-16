#include "cub3d.h"

// void	put_player_on_mini_map(t_game *game)
// {
// 	mlx_pixel_put(game->mlx, game->window, game->player.position_y, game->player.position_x, )
// }

// void	load_xpm(t_sprite *sprite, char *path, mlx_t *mlx)
// {
// 	sprite->xpm = mlx_load_xpm42(path);
// 	sprite->img = mlx_texture_to_image(mlx, &sprite->xpm->texture);
// }

// void	put_img(t_game *game, int x, int y)
// {
// 	void	*mlx;
// 	void	*window;
// 	// dprintf(2, "here\n");
// 	mlx = game->mlx;
// 	window = game->window;
// 	if (game->map[y][x] == '1' || game->map[y][x] == '0')
// 		mlx_image_to_window(mlx, game->wall.img, (25 * x), (25 * y));
// 	else if (game->map[y][x] == 'Q')
// 		mlx_image_to_window(mlx, game->ground.img, (25 * x), (25 * y));
// 	// else if (game->map[y][x] == '\n')
// 	// 	dprintf(2, "%c\n", game->map[y][x]);
// 	// game->instance->player_pos_y = game->pos.position_y;
// 	// game->instance->player_pos_x = game->pos.position_x;
// 	// (game->mlx, game->sprite_player.img, (25 * game->player.player_mm.position_x), (25 * game->player.player_mm.position_y));
// 	//put_player_on_mini_map(game);
// 	// 	dprintf(2, "NOT SUPPOSED TO PRINT: %d\n", game->map[y][x]);
// }

void	put_mini_map_pixel(t_game *game, int x, int y)
{
	void	*mlx;
	void	*window;
	// uint8_t	color;
	int		i;
	// dprintf(2, "here\n");
	mlx = game->mlx;
	i = 0;
	window = game->window;
	if (game->map[y][x] == '1')
	{
		mlx_draw_texture(game->mini_map_img, &game->wall.xpm->texture, x * 25, y * 25);
		// while (i < (25 * 25))
		// {
		// 	//mlx_draw_texture(game->mini_map_img, &game->wall.xpm->texture, x * 25, y * 25);
		// 	// color = get_img_color(game->wall.img, i % 25, i / 25, game);
		// 	if (i % 25 == 0 || i / 25 == 0 || i % 25 == 24 || i / 25 == 24)
		// 		mlx_put_pixel(game->mini_map_img, (x * 25) + i % 25, (y * 25) + i / 25, 0xFFFFFFFF);
		// 	else
		// 		mlx_put_pixel(game->mini_map_img, (x * 25) + i % 25, (y * 25) + i / 25, 0xFF00FFFF);
		// 	i++;
		// }
	}
	else if (game->map[y][x] == 'Q')
	{
		mlx_draw_texture(game->mini_map_img, &game->ground.xpm->texture, x * 25, y * 25);
		// while (i < (25 * 25))
		// {
		// 	//color = get_img_color(game->ground.img, i % 25, i / 25, game);
			
		// 	mlx_put_pixel(game->mini_map_img, (x * 25) + i % 25, (y * 25) + i / 25, 0x000000FF);
			
		// 	//mlx_put_pixel(game->mini_map_img, (x * 25) + i % 25, (y * 25) + i / 25, 0x000000FF);
		// 	i++;
		// }
	}
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
			put_mini_map_pixel(game, x, y);
			//put_img(game, x, y);
			x++;
		}
		y++;
	}
}
