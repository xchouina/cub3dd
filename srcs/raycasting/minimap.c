#include "cub3d.h"

void	put_mini_map_pixel(t_game *game, int x, int y)
{
	void	*mlx;
	// uint8_t	color;
	int		i;
	// dprintf(2, "here\n");
	mlx = game->mlx;
	i = 0;
	
	if (game->map[y][x] == '1')
		mlx_draw_texture(game->mini_map_img, &game->wall.xpm->texture,
			x * TILE_SIZE, y * 25);
	else if (game->map[y][x] == 'Q')
		mlx_draw_texture(game->mini_map_img, &game->ground.xpm->texture,
			x * TILE_SIZE, y * 25);
}

void	map_creation(t_game *game)
{
	int	y;
	int	x;
	y = 0;
	x = 0;
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
