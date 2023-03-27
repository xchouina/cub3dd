#include "cub3d.h"

void	printing_texture(t_rays *ray, mlx_image_t *img)
{
	int		tx = (int)ray->wall[0] - ((int)ray->wall[0] / TILE_SIZE) * TILE_SIZE;
	int		ty = (int)ray->wall[1] - ((int)ray->wall[1] / TILE_SIZE) * TILE_SIZE;
	int		pix_x = ty;
	int		pix_y = wall_height / TILE_SIZE;

	if (ty == 0)
	{
		apply_shaders++;
		t = tx;
	}
}

void	print_wall(t_rays *ray, int color, mlx_image_t *img)
{
	float	wall_height;
	float	wall_width;
	float	i;
	float	x;

	if (ray->dist <= 0.0001)
		ray->dist = 0.0001;
	wall_height = (5 / ray->dist) * WIN_H;
	if (wall_height > WIN_H)
		wall_height = WIN_H;
	wall_width = (float)WIN_W / (float)NUM_RAYS;
	x = ray->id * wall_width;
	while (x < wall_width * (ray->id + 1))
	{
		i = (WIN_H / 2) - (wall_height / 2);
		while (i <= (WIN_H / 2) + (wall_height / 2))
		{
			mlx_put_pixel(img, x, i, game->tab[pix_y][pix_x]);
			i++;
		}
		x++;
	}
}



// black	= rgb_to_int(0, 0, 0)
// red		= rgb_to_int(255, 0, 0)
// green	= rgb_to_int(0, 255, 0);
// blue	= rgb_to_int(0, 0, 255);