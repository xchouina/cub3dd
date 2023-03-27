#include "cub3d.h"

void	create_rays(t_game *game)
{
	int	i;

	i = -1;
	game->rays = malloc(sizeof(t_rays) * NUM_RAYS);
	while (++i < NUM_RAYS)
	{
		game->rays[i].angle = (game->player.degrees - (FOV/2)) + (i * (game->ang_incr));
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

int	check(t_game *game, t_rays *ray, float x, float y, int checking)
{
	int		cx;
	int		cy;

	cx = (game->player.cx + x) / TILE_SIZE;
	cy = (game->player.cy + y) / TILE_SIZE;
	if (ray->angle >= 0 && ray->angle <= 180 && checking == 0)
		cy -= 1;
	if (ray->angle >= 90 && ray->angle <= 270 && checking == 1)
		cx -= 1;
	if (cx < 0 || cx >= game->map_x || game->player.cx + x < 0)
		return (ret_zero(ray));
	if (cy < 0 || cy >= game->map_y || (game->player.cy + y) < 0)
		return (ret_zero(ray));
	ray->wall[0] = game->player.cx + x;
	ray->wall[1] = game->player.cy + y;
	if (game->square_map[cy][cx] == '1')
		return (1);
	return (0);
}

int	check_l(t_game *game, t_rays *ray, float x, float y, int checking)
{
	int	cx;
	int	cy;

	if (x <= 0 || (x / TILE_SIZE) >= game->map_x || y <= 0 || (y / TILE_SIZE) >= game->map_y)
		return (ret_zero(ray));
	cx = x / TILE_SIZE;
	cy = y / TILE_SIZE;
	if (ray->angle > 0 && ray->angle < 180 && checking == 0)
		cy -= 1;
	if (ray->angle > 90 && ray->angle < 270 && checking == 1)
		cx -= 1;
	if (cx < 0 || cx >= game->map_x)
		return (ret_zero(ray));
	if (cy < 0 || cy >= game->map_y)
		return (ret_zero(ray));
	ray->wall[0] = x;
	ray->wall[1] = y;
	if (game->square_map[cy][cx] == '1')
		return (1);
	return (0);
}

void	loop_check_h(t_game *game, t_rays *ray, float theta)
{
	ray->y = TILE_SIZE;
	ray->x = ray->y / tanf(deg2rad(theta));
	fix_sign(ray);
	while (!ray->h_wall_found)
	{
		ray->h_wall_found = check_l(game, ray, ray->h_check[0] + ray->x, ray->h_check[1] + ray->y, 0);
		ray->h_check[0] = ray->wall[0];
		ray->h_check[1] = ray->wall[1];
		if (ray->h_check[0] <= (float)0 && ray->h_check[1] <= (float)0)
		{
			ray->h_wall_found = 0;
			return ;
		}
	}
}

void	loop_check_v(t_game *game, t_rays *ray, float theta)
{
	ray->x = TILE_SIZE;
	ray->y = ray->x * tanf(deg2rad(theta));
	fix_sign(ray);
	while (!ray->v_wall_found)
	{
		ray->v_wall_found = check_l(game, ray, ray->v_check[0] + ray->x, ray->v_check[1] + ray->y, 1);
		ray->v_check[0] = ray->wall[0];
		ray->v_check[1] = ray->wall[1];
		if (ray->v_check[0] <= (float)0 && ray->v_check[1] <= (float)0)
		{
			ray->v_wall_found = 0;
			return ;
		}
	}
}

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

int	horiz_wall(t_game *game, t_rays *ray)
{
	float	h_dist;
	float	v_dist;

	h_dist = sqrtf(powf(ray->h_check[1] - game->player.cy, 2) + powf(ray->h_check[0] - game->player.cx, 2));
	v_dist = sqrtf(powf(ray->v_check[1] - game->player.cy, 2) + powf(ray->v_check[0] - game->player.cx, 2));
	if ((!ray->v_wall_found || h_dist < v_dist) && (ray->h_check[1] && ray->h_check[0]))
	{
		ray->dist = h_dist;
		ray->wall[0] = ray->h_check[0];
		ray->wall[1] = ray->h_check[1];
		return (1);
	}
	ray->dist = v_dist;
	ray->wall[0] = ray->v_check[0];
	ray->wall[1] = ray->v_check[1];
	return (0);
}

void	fix_fisheye(t_game *game, t_rays *ray)
{
	ray->dist = roundf((ray->dist * cosf(deg2rad(ray->angle - game->player.degrees)) * 100000)) / 100000;
	// ********
	// dprintf(2, "%f degrees : Wall distance = %f\n", ray->angle, ray->dist);
	// dprintf(2, "wall coordinates: (%f, %f)\n", ray->wall[0], ray->wall[1]);
}
// ===============================================================******
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
			mlx_put_pixel(img, x, i, color);
			i++;
		}
		x++;
	}
}
// ===============================================================******

void	cast_rays(t_game *game)
{
	int	i;

	i = 0;
	create_rays(game);
	while (i < NUM_RAYS)
	{
		check_horizontal(game, &game->rays[i]);
		check_vertical(game, &game->rays[i]);
		if (horiz_wall(game, &game->rays[i]) && game->rays[i].h_wall_found)
		{
			fix_fisheye(game, &game->rays[i]);
			if (game->rays[i].angle >= 0 && game->rays[i].angle <= 180)
				print_wall(&game->rays[i], 0XA349A4AA, game->img); //north red
			else
				print_wall(&game->rays[i], 0X9370DBFF, game->img); //south purple
		}
		else if (game->rays[i].v_wall_found == 1)
		{
			fix_fisheye(game, &game->rays[i]);
			if (game->rays[i].angle >= 90 && game->rays[i].angle <= 270)
				print_wall(&game->rays[i], 0XFFD700FF, game->img); //west yellow
			else
				print_wall(&game->rays[i], 0XFF8C00FF, game->img); //east orange
		}
		// draw_line(game->player.cx, game->player.cy, game->rays[i].wall[0], game->rays[i].wall[1], game->img);
		// printf("(%d ; %d) --> (%d ; %d)\n", (int)game->rays[i].wall[0], (int)game->rays[i].wall[1], ((int)game->rays[i].wall[0] - ((int)game->rays[i].wall[0] / TILE_SIZE) * TILE_SIZE), ((int)game->rays[i].wall[1] - ((int)game->rays[i].wall[1] / TILE_SIZE) * TILE_SIZE));
		i++;
	}
	// printf("%d , %d\n", game->map_x, game->map_y);
	free(game->rays);
}


// (int)game->rays[i].wall[0] - ((int)game->rays[i].wall[0] / TILE_SIZE) * TILE_SIZE

// rgb_to_int(195, 0, 0)
// rgb_to_int(150, 0, 195)
// rgb_to_int(255, 205, 51)
// rgb_to_int(255, 126, 51)
