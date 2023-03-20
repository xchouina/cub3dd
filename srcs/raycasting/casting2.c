#include "../includes/cub3d.h"

void	create_rays(t_game *game)
{
	int	i;

	i = -1;
	game->rays = malloc(sizeof(t_rays) * NUM_RAYS);
	while (++i <= NUM_RAYS)
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

int	check(t_game *game, t_rays *ray, float x, float y)
{
	int		cx;
	int		cy;

	cx = (game->player.cx + x) / TILE_SIZE;
	cy = (game->player.cy + y) / TILE_SIZE;
	if (ray->angle > 0 && ray->angle < 180)
		cy -= 1;
	if (ray->angle > 90 && ray->angle < 270)
		cx -= 1;
	if (cx < 0 || cx >= game->max_line)
		return (ret_zero(ray));
	if (cy < 0 || cy >= game->map_height)
		return (ret_zero(ray));
	ray->wall[0] = game->player.cx + x;
	ray->wall[1] = game->player.cy + y;
	// dprintf(2, "checking [%d][%d]\n", cx, cy);
	if (game->map[cy][cx] == 1)
		return (1);
	return (0);
}

// void	loop_check_h(t_game *game, t_rays *ray, float theta)
// {
// 	while (!ray->h_wall_found)
// 	{

// 	}
// }

void	first_check_h(t_game *game, t_rays *ray, float theta)
{
	if (ray->angle > 180 && ray->angle < 360)
		ray->y = TILE_SIZE - game->player.dy;
	else
		ray->y = game->player.dy;
	ray->x = ray->y / tanf(deg2rad(theta));
	// dprintf(2, "first check horizontal %d: \nangle: %f\nx: %f\ny: %f\n\n", ray->id, ray->angle, ray->x, ray->y);
	fix_sign(ray);
	ray->h_wall_found = check(game, ray, ray->x, ray->y);
	// printf("Here: h_wall_found = %d | x = %f | y = %f\n",ray->h_wall_found, ray->x, ray->y);
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
	// dprintf(2, "first check horizontal %d: \nangle: %f\nx: %f\ny: %f\n\n", ray->id, ray->angle, ray->x, ray->y);
	fix_sign(ray);
	ray->v_wall_found = check(game, ray, ray->x, ray->y);
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
	// if (!ray->h_wall_found)
		// loop_check_h(game, ray, theta);
}

void	check_vertical(t_game *game, t_rays *ray)
{
	float	theta;

	theta = ray->angle;
	if ((ray->angle > 90 && ray->angle < 180) || (ray->angle > 270 && ray->angle < 360))
		theta = 360 - ray->angle;
	first_check_v(game, ray, theta);
	// if (!ray->v_wall_found)
	// 	loop_check_v(game, ray, theta);
}

int	horiz_wall(t_game *game, t_rays *ray)
{
	// if horiz < vert ret 1
	float	h_dist;
	float	v_dist;

	h_dist = sqrtf(powf(ray->h_check[1] - game->player.cy, 2) + powf(ray->h_check[0] - game->player.cx, 2));
	v_dist = sqrtf(powf(ray->v_check[1] - game->player.cy, 2) + powf(ray->v_check[0] - game->player.cx, 2));
	if (!ray->v_wall_found || h_dist <= v_dist) //if == , corner??
	{
		ray->dist = h_dist;
		ray->wall[0] = ray->h_check[0];
		ray->wall[1] = ray->h_check[1];
		return (1);
	}
	ray->dist = v_dist;
	ray->wall[0] = ray->v_check[0];
	ray->wall[1] = ray->v_check[1];
	dprintf(2, "distance = %f\n", ray->dist);
	dprintf(2, "wall values at %f: (%f, %f)\n", ray->angle, ray->v_check[0], ray->v_check[1]);
	return (0);
}

// void	fix_fisheye(t_game *game, t_rays *ray)
// {
// 	ray->dist = roundf((ray->dist * cosf(deg2rad(ray->angle - game->player.degrees)) * 100000)) / 100000;
// }

//print_walls change color for texture
void	print_wall(t_rays *ray, int color, mlx_image_t *img)
{
	int	wall_height;
	int	wall_width;
	int	i;
	int	x;

	if (ray->dist <= 0.0001)
		ray->dist = 0.0001;

	wall_height = (2 / ray->dist) * WIN_H;
	if (wall_height > WIN_H - 100)
		wall_height = WIN_H - 100;
	// if (wall_height >= 350)
	// 	wall_height = 350;
	// dprintf(2, "distance : %f WALL HEIGHT : %d\n", ray->dist, wall_height);
	wall_width = WIN_W / NUM_RAYS;
	x = ray->id * wall_width;
	while (x <= wall_width * (ray->id + 1))
	{
		i = (WIN_H / 2) - (wall_height / 2);
		while (i <= (WIN_H / 2) + (wall_height / 2))
		{
			mlx_put_pixel(img, x, i++, color);
			i++;
		}
		x++;
	}
}

void	cast_rays(t_game *game)
{
	int	i;

	i = -1;
	create_rays(game);
	while (++i <= NUM_RAYS)
	{
		check_horizontal(game, &game->rays[i]);
		check_vertical(game, &game->rays[i]);
		// distance horizontal vs vertical
		if (game->rays[i].h_wall_found == 1)
			dprintf(2, "horizontal wall found for %f degrees: (%f, %f)\n", game->rays[i].angle, game->rays[i].h_check[0], game->rays[i].h_check[1]);
		if (game->rays[i].v_wall_found == 1)
			dprintf(2, "vertical wall found for %f degrees: (%f, %f)\n", game->rays[i].angle, game->rays[i].v_check[0], game->rays[i].v_check[1]);
		// mlx_pixel_put(game->display.mlx, game->display.mlx_win, (int)game->rays[i].v_check[0], game->rays[i].v_check[1], 0xFF00FF);
		
		// draw_line(game, game->mini_map_img); //2D LINE ONE MINIMAP
		if (horiz_wall(game, &game->rays[i]) && game->rays[i].h_wall_found)
		{
			fix_fisheye(game, &game->rays[i]);
			if (game->rays[i].angle > 0 && game->rays[i].angle < 180)
				print_wall(&game->rays[i], rgb_to_int(195, 0, 0), game->img); //north red
			else
				print_wall(&game->rays[i], rgb_to_int(150, 0, 195), game->img); //south purple
		}
		else
		{
			fix_fisheye(game, &game->rays[i]);
			if (game->rays[i].angle > 90 && game->rays[i].angle < 270)
				print_wall(&game->rays[i], rgb_to_int(255, 205, 51), game->img); //west yellow
			else
				print_wall(&game->rays[i], rgb_to_int(255, 126, 51), game->img); //east orange
		}
	}
}
