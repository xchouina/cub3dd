#include "../includes/cub3d.h"

// CONVERT DEGREE TO RADIANS
float	deg2rad(float degrees) 
{
    return (degrees * M_PI) / 180.0;
}
// FIX ANGLE OVER 360 || UNDER 0
int FixAng(int a)
{
	if (a > 359)
		a -= 360; 
	if (a < 0)
		a+=360;
	return a;
}

// void	fix_fisheye(t_game *game, t_rays *ray)
// {
// 	ray->dist = roundf((ray->dist * cosf(deg2rad(ray->angle - game->player.degrees)) * 100000)) / 100000;
// 	// dprintf(2, "distance finale = %f\n", ray->dist);
// }

void	draw_line(float x1, float y1, float x2, float y2, mlx_image_t *img)
{
	float	delta_x;
	float	delta_y;
	float	step;
	float	x;
	float	y;
	int		i;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	step = (fabs(delta_x) > fabs(delta_y)) ? fabs(delta_x) : fabs(delta_y);
	delta_x /= step;
	delta_y /= step;
	x = x1;
	y = y1;
	i = 0;
	while (i <= step)
	{
		mlx_put_pixel(img, x, y, 0XFFFF00FF);
		x += delta_x;
		y += delta_y;
		i++;
	}
}


int	rgbtab_to_int(char **rgb)
{
	return ((ft_atoi(rgb[0]) << 24) + (ft_atoi(rgb[1]) << 16) + (ft_atoi(rgb[2]) << 8) + 255);
}

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 24) + (g << 16) + (b << 8) + 255);
}

// uint32_t	rgba_to_int(int r, int g, int b, int a)
// {
// 	return ((r << 24) + (g << 16) + (b << 8) + (a));
// }

uint32_t	rgba_to_int(int r, int g, int b, int a)
{
	return ((r << 24) | (g << 16) | (b << 8) | (a));
}
