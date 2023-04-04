#include "cub3d.h"


int		adding_shadder(int	hexa, int shader)
{
	
}
void	printing_texture(t_rays *ray, mlx_image_t *img)
{
	// int		wx = (int)ray->wall[0] - ((int)ray->wall[0] / TILE_SIZE) * TILE_SIZE;
	// int		wy = (int)ray->wall[1] - ((int)ray->wall[1] / TILE_SIZE) * TILE_SIZE;
	// if (wy == 0)
	// {
	// 	apply_shaders++;
	// 	int  starter_x = wx;
	// }

	// int	h_ratio = wall_height / texture_height;
	// int	vy = 0;

	int h_count = 0;
	while (h_count < h_ratio)
	{
		mlx_put_pixel(img, x, y, game->tab[vy][starter_x]);
		y++;
		h_count++;
	}
	vy++;
	

}

void	print_wall(t_rays *ray, int color, mlx_image_t *img)
{
	float	wall_height;
	float	wall_width;
	float	y;
	float	x;
// ----------------------------------------

	int		wx = (int)ray->wall[0] - ((int)ray->wall[0] / TILE_SIZE) * TILE_SIZE;
	int		wy = (int)ray->wall[1] - ((int)ray->wall[1] / TILE_SIZE) * TILE_SIZE;
	int  starter_x;
	if (wy == 0)
		starter_x = wx;
	int	h_ratio = wall_height / 25; //texture_height;
	int	vy = 0;
	int h_count = 0;
// ----------------------------------------

	if (ray->dist <= 0.0001)
		ray->dist = 0.0001;
	wall_height = (5 / ray->dist) * WIN_H;
	if (wall_height > WIN_H)
		wall_height = WIN_H;
	wall_width = (float)WIN_W / (float)NUM_RAYS;
	x = ray->id * wall_width;
	while (x < wall_width * (ray->id + 1))
	{
		y = (WIN_H / 2) - (wall_height / 2);
		while (y <= (WIN_H / 2) + (wall_height / 2))
		{
			h_count = 0;
			while (h_count < h_ratio)
			{
				mlx_put_pixel(img, x, y, game->tab[vy][starter_x]);
				y++;
				h_count++;
			}
			vy++;
		}
		x++;
	}
}

// black	= rgb_to_int(0, 0, 0)
// red		= rgb_to_int(255, 0, 0)
// green	= rgb_to_int(0, 255, 0);
// blue		= rgb_to_int(0, 0, 255);