#include "cub3d.h"

void	put_cube(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;

	while (i <= TILE_SIZE)
	{
		j = 0;
		while (j <= TILE_SIZE)
		{
			if (i % TILE_SIZE != 0 || j % TILE_SIZE != 0)
				mlx_put_pixel(game->img, ((y * TILE_SIZE) + i), ((x * TILE_SIZE) + j), color);
			if (i % TILE_SIZE == 0 || j % TILE_SIZE == 0)
				mlx_put_pixel(game->img, ((y * TILE_SIZE) + i), ((x * TILE_SIZE) + j), 0xFFFFFF);
			j++;
		}
		i++;
	}
}

void	print_player(t_game *game, int cx, int cy)
{
	int	i;
	int	j;
	int	size;

	size = 2;
	i = cx - size;
	while (i < cx + size)
	{
		j = cy - size;
		while (j < cy + size)
		{
			mlx_put_pixel(game->img, i, j, 0x0000FF);
			j++;
		}
		i++;
	}
}

void	print_minimap(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_height)
	{
		y = 0;
		while (y < game->map_height)
		{
			if (game->square_map[x][y] == '1')
				put_cube(game, y, x, rgb_to_int(100, 103, 100));
			else if (game->square_map[x][y] == 'Q')
				put_cube(game, y, x, rgb_to_int(195, 3, 250));
			y++;
		}
		x++;
	}
	print_player(game, game->player.cx, game->player.cy);
}














// void	put_mini_map_pixel(t_game *game, int x, int y)
// {
// 	void	*mlx;
// 	int		i;
	
// 	mlx = game->mlx;
// 	i = 0;
// 	if (game->square_map[y][x] == '1')
// 		mlx_draw_texture(game->mini_map_img, &game->wall.xpm->texture, x * 25, y * 25);
// 	else if (game->map[y][x] == 'Q')
// 		mlx_draw_texture(game->mini_map_img, &game->ground.xpm->texture,
// 			x * TILE_SIZE, y * 25);
// }

// void	map_creation(t_game *game)
// {
// 	int	y;
// 	int	x;
	
// 	y = 0;
// 	x = 0;
// 	while (game->square_map[y] != NULL)
// 	{
// 		x = 0;
// 		while (game->square_map[y][x] != '\n')
// 		{
// 			if (game->square_map[y][x] == '\0')
// 				break ;
// 			put_mini_map_pixel(game, x, y);
// 			x++;
// 		}
// 		y++;
// 	}
// }
// ------------------
