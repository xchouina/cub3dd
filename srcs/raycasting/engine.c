#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_game	*game, int x, int y, int color)
{
	char	*dst;

	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

uint8_t	get_img_color(mlx_image_t *img, int x, int y, t_game *game)
{
	uint8_t	color;
	(void)game;
	color = *(img->pixels + ((y * img->width) + (x)));
	// color = *(img->pixels + (y * game->line_length + x * (game->bits_per_pixel / 8)));
	return (color);
}

void	sky_n_ground(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = -1;
	while (x < game->res_x)
	{
		while (++y < game->res_y)
			mlx_put_pixel(game->img, x, y, game->textures.couleur_floor);
		y = -1;
		x++;
	}
	x = 0;
	y = -1;
	while (x < (game->res_x))
	{
		while (++y < (game->res_y / 2))
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
	int	width;
	int	height;

	game->res_x = 1920;
	game->res_y = 1080;
	game->mlx = mlx_init(game->res_x, game->res_y, "Cub3d", true);
	// game->window = (void *)mlx_new_window(game->mlx, game->res_x, game->res_y, "cub3d");
	game->img = mlx_new_image(game->mlx, game->res_x, game->res_y);
	game->mini_map_img = mlx_new_image(game->mlx, game->res_x, game->res_y);
	//game->sprite_player.img = mlx_new_image(game->mlx, game->res_x, game->res_y);
	// game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length,
								// &game->endian);
	game->map_x = (ft_strlen(game->square_map[0]) - 1);
	// dprintf(2, "%d\n", game->map_x);
	game->map_y = game->map_height - 1;
	// dprintf(2, "%d\n", game->map_y);

	width = 100;
	height = 100;
	load_xpm(&game->wall, "./textures/2d_wall.xpm42", game->mlx);
	load_xpm(&game->ground, "./textures/2d_ground.xpm42", game->mlx);
	// printf("img_width = %d\n", game->wall.img->width);
	// printf("img_width = %d\n", game->wall.img->height);
	//game->sprite_player.xpm = mlx_load_xpm42("./textures/ylw_dot.xpm42");
	load_xpm(&game->sprite_player, "./textures/ylw_dot.xpm42", game->mlx);
	//mlx_delete_xpm42(game->sprite_player.xpm);
}

int	starting_engine(t_game	*game)
{
	init_assets(game);
	sky_n_ground(game);
	// cube_pixel(game, 100, 100);
	// mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
	// ft_arrayprint(game->map);
	map_creation(game);
	// mlx_put_image_to_window(game->mlx, game->window, game->player_mm, (25 * 4), (25 * 4));
	// dprintf(2, "HELLO\n");
	// mlx_put_image_to_window(game->mlx, game->window, game->ground_mm, (25 * 0), (25 * 0));

	// mlx_hook(game->window, 2, 0, &events, &game);

	
	return (0);
}
