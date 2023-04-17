#include "../includes/cub3d.h"

void	sky_n_ground(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y <= WIN_H / 2)
	{
		while (++x <= WIN_W)
			mlx_put_pixel(game->img, x, y, game->textures.couleur_sky);
		x = -1;
	}
	while (y <= WIN_H)
	{
		while (++x <= WIN_W)
			mlx_put_pixel(game->img, x, y, game->textures.couleur_floor);
		x = -1;
		y++;
	}
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

void	find_starting_angle(t_game *game)
{
	if (game->player.carddir == 'N')
		game->player.degrees = 90.0f;
	if (game->player.carddir == 'W')
		game->player.degrees = 180.0f;
	if (game->player.carddir == 'S')
		game->player.degrees = 270.0f;
	if (game->player.carddir == 'E')
		game->player.degrees = 360.0f;
}

void	init_player_data(t_game *game)
{
	game->player.x = game->player.player_mm.position_x;
	game->player.y = game->player.player_mm.position_y;
	game->player.cx = game->player.x * TILE_SIZE + (TILE_SIZE / 2);
	game->player.cy = game->player.y * TILE_SIZE + (TILE_SIZE / 2);
	game->player.dx = game->player.cx - (game->player.x * TILE_SIZE);
	game->player.dy = game->player.cy - (game->player.y * TILE_SIZE);
	game->delta_x = cos(deg2rad(game->player.degrees));
	game->delta_y = -sin(deg2rad(game->player.degrees));
}

void	init_assets(t_game	*game)
{
	game->mlx = mlx_init(WIN_W, WIN_H, "Cub3d", true);
	game->img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	game->mini_map_img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	game->ang_incr = (float)FOV / (float)NUM_RAYS;
	game->map_x = game->max_line;
	game->map_y = game->height_q + 1;
	game->delta_x = cos(deg2rad(90));
	game->delta_y = -sin(deg2rad(90));
	find_starting_angle(game);
}

int	starting_engine(t_game	*game)
{
	init_assets(game);
	init_player_data(game);
	render(game);
	return (0);
}
