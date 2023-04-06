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

// void	draw_line(t_game *game, mlx_image_t *img)
// {
// 	t_line	line;

// 	line.player_center_x = game->player.x + (25 / 2);
// 	line.player_center_y = game->player.y + (25 / 2);
// 	line.dx = game->player.cx - line.player_center_x;
// 	line.dy = game->player.cy - line.player_center_y;
// 	line.steps = abs(line.dx) > abs(line.dy) ? abs(line.dx) : abs(line.dy);
// 	line.xinc = (float) line.dx / (float) line.steps;
// 	line.yinc = (float) line.dy / (float) line.steps;
// 	line.x = line.player_center_x;
// 	line.y = line.player_center_y;
// 	line.i = 0;
// 	while (line.i++ <= line.steps)
// 	{
// 		if (line.x >= 0 && line.x < img->width && line.y >= 0 && line.y < img->height) 
// 		mlx_put_pixel(img, line.x, line.y, 0XFFFF00FF);
// 		line.x += line.xinc;
// 		line.y += line.yinc;
// 	}
// }

int	rgbtab_to_int(char **rgb)
{
	return ((ft_atoi(rgb[0]) << 24) + (ft_atoi(rgb[1]) << 16) + (ft_atoi(rgb[2]) << 8) + 255);
}

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 24) + (g << 16) + (b << 8) + 255);
}

int	rgba_to_int(int r, int g, int b, int a)
{
	return ((r << 24) + (g << 16) + (b << 8) + (a));
}
