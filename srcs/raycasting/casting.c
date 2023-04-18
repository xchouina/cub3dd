#include "cub3d.h"

void	create_rays(t_game *game)
{
	int	i;

	i = -1;
	game->rays = malloc(sizeof(t_rays) * NUM_RAYS);
	while (++i < NUM_RAYS)
	{
		game->rays[i].angle = (game->player.degrees
				- (FOV / 2)) + (i * (game->ang_incr));
		if (game->rays[i].angle >= 360)
			game->rays[i].angle -= 360;
		if (game->rays[i].angle < 0)
			game->rays[i].angle += 360;
		game->rays[i].x = 0;
		game->rays[i].y = 0;
		game->rays[i].id = i;
		game->rays[i].dist = i;
		game->rays[i].h_wall_found = 0;
		game->rays[i].v_wall_found = 0;
		game->rays[i].wall[0] = 0;
		game->rays[i].wall[1] = 0;
	}
}

void	fix_sign(t_rays *ray)
{
	if (ray->angle > 0 && ray->angle < 180)
		ray->y = -ray->y;
	if (ray->angle > 90 && ray->angle < 270)
		ray->x = -ray->x;
	if (ray->angle == 90 || ray->angle == 270)
		ray->x = 0;
	if (ray->angle == 0 || ray->angle == 180)
		ray->y = 0;
}

int	ret_zero(t_rays *ray)
{
	ray->wall[0] = 0;
	ray->wall[1] = 0;
	return (0);
}

void	wall_orientaion(t_game *game, int x, int i, int o)
{
	int	dir;

	if (o == 1)
	{
		if (game->rays[i].angle >= 0 && game->rays[i].angle <= 180)
			dir = 0;
		else
			dir = 1;
	}
	if (o == 2)
	{
		if (game->rays[i].angle >= 90 && game->rays[i].angle <= 270)
			dir = 2;
		else
			dir = 3;
	}
	fix_fisheye(game, &game->rays[i]);
	print_wall(game, &game->rays[i], x, dir);
}

void	cast_rays(t_game *game)
{
	int	i;
	int	x;

	i = -1;
	create_rays(game);
	while (++i < NUM_RAYS)
	{
		check_horizontal(game, &game->rays[i]);
		check_vertical(game, &game->rays[i]);
	}
	x = 0;
	i = 0;
	while (x < WIN_W && i < NUM_RAYS)
	{
		i = (float)x / ((float)WIN_W / (float)NUM_RAYS);
		if (horiz_wall(game, &game->rays[i]) && game->rays[i].h_wall_found)
			wall_orientaion(game, x, i, 1);
		else if (game->rays[i].v_wall_found == 1)
			wall_orientaion(game, x, i, 2);
		x++;
	}
	free(game->rays);
}
