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

int	rgbtab_to_int(char **rgb)
{
	return ((ft_atoi(rgb[0]) << 24) + (ft_atoi(rgb[1]) << 16) + (ft_atoi(rgb[2]) << 8) + 255);
}

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 24) + (g << 16) + (b << 8) + 255);
}

uint32_t	rgba_to_int(int r, int g, int b, int a)
{
	return ((r << 24) | (g << 16) | (b << 8) | (a));
}
