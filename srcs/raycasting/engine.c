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

	x = 0;
	y = -1;
	while (x < 1920)
	{
		while (++y < 1080)
			mlx_put_pixel(game->img, x, y, game->textures.couleur_floor);
		y = -1;
		x++;
	}
	x = 0;
	y = -1;
	while (x < (1920))
	{
		while (++y < (1080 / 2))
			mlx_put_pixel(game->img, x, y, game->textures.couleur_sky);
		y = -1;
		x++;
	}
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

void	load_xpm(t_sprite *sprite, char *path, mlx_t *mlx)
{
	sprite->xpm = mlx_load_xpm42(path);
	sprite->img = mlx_texture_to_image(mlx, &sprite->xpm->texture);
}

void	init_assets(t_game	*game)
{
	game->mlx = mlx_init(1920, 1080, "Cub3d", true);
	game->img = mlx_new_image(game->mlx, 1920, 1080);
	game->mini_map_img = mlx_new_image(game->mlx, 1920, 1080);
	//game->sprite_player.img = mlx_new_image(game->mlx, game->res_x, game->res_y);
	// game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length,
								// &game->endian);
	game->map_x = (ft_strlen(game->square_map[0]) - 1);
	// dprintf(2, "%d\n", game->map_x);
	game->map_y = game->map_height - 1;
	game->delta_x = cos(deg2rad(90));
	game->delta_y = -sin(deg2rad(90));
	game->ray_angle = 90.0f;
	load_xpm(&game->wall, "./textures/2d_wall.xpm42", game->mlx);
	load_xpm(&game->ground, "./textures/2d_ground.xpm42", game->mlx);
	load_xpm(&game->sprite_player, "./textures/ylw_dot.xpm42", game->mlx);
}

int	starting_engine(t_game	*game)
{

	init_assets(game);
	// init_raycast_assets(game);
	sky_n_ground(game);
	map_creation(game);
	return (0);
}
