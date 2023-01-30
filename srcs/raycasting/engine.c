#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_game	*game, int x, int y, int color)
{
	char	*dst;

	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	sky_n_ground(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->res_x)
	{
		while (++y < game->res_y)
			my_mlx_pixel_put(game, x, y, 0x0099FF99);
		y = 0;
		x++;
	}
	x = 0;
	y = 0;
	while (x < (game->res_x))
	{
		while (++y < (game->res_y / 2))
			my_mlx_pixel_put(game, x, y, 0x00CCFFFF);
		y = 0;
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
}

void	init_assets(t_game	*game)
{
	int	width;
	int	height;

	game->res_x = 1920;
	game->res_y = 1080;
	game->mlx = mlx_init();	
	game->window = mlx_new_window(game->mlx, game->res_x, game->res_y, "cub3d");
	game->img = mlx_new_image(game->mlx, game->res_x, game->res_y);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length,
								&game->endian);
	game->map_x = (ft_strlen(game->map[0]) - 1);
	// dprintf(2, "%d\n", game->map_x);
	game->map_y = game->map_height - 1;
	// dprintf(2, "%d\n", game->map_y);

	width = 100;
	height = 100;
	game->player_mm = mlx_xpm_file_to_image(game->mlx,
			"../../textures/ylw_dot.xpm", &width, &height);
	game->wall_mm = mlx_xpm_file_to_image(game->mlx,
			"textures/2d_wall.xpm", &width, &height);
	game->ground_mm = mlx_xpm_file_to_image(game->mlx,
			"textures/2d_ground.xpm", &width, &height);
}

void	starting_engine(t_game	*game)
{
	init_assets(game);
	sky_n_ground(game);
	// cube_pixel(game, 100, 100);
	// mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
	ft_arrayprint(game->map);
	map_creation(game);
	dprintf(2, "HELLO\n");
	// mlx_put_image_to_window(game->mlx, game->window, game->wall_mm, (25 * 1), (25 * 1));
	// mlx_put_image_to_window(game->mlx, game->window, game->ground_mm, (25 * 0), (25 * 0));

	mlx_loop(game->mlx);
}



