#include "../includes/cub3d.h"

uint8_t	get_img_color(mlx_image_t *img, int x, int y, t_game *game)
{
	uint8_t	color;
	(void)game;
	color = *(img->pixels + ((y * img->width) + (x)));
	return (color);
}

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

void	load_xpm(t_sprite *sprite, char *path, mlx_t *mlx)
{
	sprite->xpm = mlx_load_xpm42(path);
	sprite->img = mlx_texture_to_image(mlx, &sprite->xpm->texture);
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
	// game->player.x = (int)game->player.cx / TILE_SIZE;
	// game->player.y = (int)game->player.cy / TILE_SIZE;
	
	game->player.cx = game->player.x * TILE_SIZE + (TILE_SIZE / 2);
	game->player.cy = game->player.y * TILE_SIZE + (TILE_SIZE / 2);
	// game->player.cx = game->sprite_player.img->instances[0].x;
	// game->player.cy = game->sprite_player.img->instances[0].y;
	game->player.dx = game->player.cx - (game->player.x * TILE_SIZE);
	game->player.dy = game->player.cy - (game->player.y * TILE_SIZE);

	game->delta_x = cos(deg2rad(game->player.degrees));
	game->delta_y = -sin(deg2rad(game->player.degrees));
	// printf("x: %d\ny: %d\ncx: %f\ncy: %f\ndx: %f\ndy: %f\ncarddir: %c\ndegrees: %f\nrad: %f\n",
	// game->player.x,
	// game->player.y,
	// game->player.cx,
	// game->player.cy,
	// game->player.dx,
	// game->player.dy,
	// game->player.carddir,
	// game->player.degrees,
	// game->player.rad);
}

void	init_assets(t_game	*game)
{
	game->mlx = mlx_init(WIN_W, WIN_H, "Cub3d", true);
	game->img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	game->mini_map_img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	game->ang_incr = (float)FOV / (float)NUM_RAYS;
	//game->sprite_player.img = mlx_new_image(game->mlx, game->res_x, game->res_y);
	// game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length,
								// &game->endian);
	game->map_x = (ft_strlen(game->square_map[0]) - 1);
	// dprintf(2, "%d\n", game->map_x);
	game->map_y = game->map_height - 1;
	game->delta_x = cos(deg2rad(90));
	game->delta_y = -sin(deg2rad(90));
	find_starting_angle(game);
	// init_player_data(game);
	// load_xpm(&game->wall, "./textures/2d_wall.xpm42", game->mlx);
	// load_xpm(&game->ground, "./textures/2d_ground.xpm42", game->mlx);
	load_xpm(&game->sprite_player, "./textures/ylw_dot.xpm42", game->mlx);
}

int	starting_engine(t_game	*game)
{
	// printf("-->\n");
	// game->map_str = ft_double_2_singlearray(game->map);
	// printf("-->\n%s\n", game->map_str);
	init_assets(game);
	init_player_data(game);
	render(game);
	return (0);
}
