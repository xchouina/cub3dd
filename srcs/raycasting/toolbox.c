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
