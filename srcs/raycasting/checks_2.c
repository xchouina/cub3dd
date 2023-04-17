#include "cub3d.h"

void	first_check_h(t_game *game, t_rays *ray, float theta)
{
	if (ray->angle > 180 && ray->angle < 360)
		ray->y = TILE_SIZE - game->player.dy;
	else
		ray->y = game->player.dy;
	ray->x = ray->y / tanf(deg2rad(theta));
	fix_sign(ray);
	ray->h_wall_found = check(game, ray, ray->x, ray->y, 0);
	if (ray->wall[0] == (float)0 || ray->wall[1] == (float)0)
		ray->h_wall_found = 0;
	ray->h_check[0] = ray->wall[0];
	ray->h_check[1] = ray->wall[1];
}

void	first_check_v(t_game *game, t_rays *ray, float theta)
{
	if ((ray->angle >= 0 && ray->angle <= 90) || (ray->angle >= 270 && ray->angle < 360))
		ray->x = TILE_SIZE - game->player.dx;
	else
		ray->x = game->player.dx;
	ray->y = ray->x * tanf(deg2rad(theta));
	fix_sign(ray);
	ray->v_wall_found = check(game, ray, ray->x, ray->y, 1);
	if (ray->wall[0] == (float)0 || ray->wall[1] == (float)0)
		ray->v_wall_found = 0;
	ray->v_check[0] = ray->wall[0];
	ray->v_check[1] = ray->wall[1];
}

void	check_horizontal(t_game *game, t_rays *ray)
{
	float	theta;

	theta = ray->angle;
	if ((ray->angle > 90 && ray->angle < 180) || (ray->angle > 270 && ray->angle < 360))
		theta = 360 - ray->angle;
	first_check_h(game, ray, theta);
	if (!ray->h_wall_found && ray->h_check[0] != (float)0 && ray->h_check[1] != (float)0)
		loop_check_h(game, ray, theta);
}

void	check_vertical(t_game *game, t_rays *ray)
{
	float	theta;

	theta = ray->angle;
	if ((ray->angle > 90 && ray->angle < 180) || (ray->angle > 270 && ray->angle < 360))
		theta = 360 - ray->angle;
	first_check_v(game, ray, theta);
	if (!ray->v_wall_found && ray->v_check[0] != (float)0 && ray->v_check[1] != (float)0)
		loop_check_v(game, ray, theta);
}
