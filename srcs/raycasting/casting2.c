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
	// dprintf(2, "x : %f y : %f\n", (game->player.cx + x), (game->player.cy + y));
	// dprintf(2, "cx : %d cy : %d\n", cx, cy);
	if (ray->angle >= 0 && ray->angle <= 180 && checking == 0)
		cy -= 1;
	if (ray->angle >= 90 && ray->angle <= 270 && checking == 1)
		cx -= 1;
	if (cx < 0 || cx >= game->max_line || game->player.cx + x < 0)
	{
		// dprintf(2, "here!\n");
		return (ret_zero(ray));
	}
	if (cy < 0 || cy >= game->map_height || (game->player.cy + y) < 0)
	{
		// dprintf(2, "cx = %d map width = %d\n", cx, game->max_line);
		// dprintf(2, "cy = %d map height = %d\n", cy, game->map_height);
		return (ret_zero(ray));
	}
	ray->wall[0] = game->player.cx + x;
	ray->wall[1] = game->player.cy + y;
	// dprintf(2, "checking [%d][%d]\n", cx, cy);
	if (game->square_map[cy][cx] == '1')
		return (1);
	return (0);
}

int	check_l(t_game *game, t_rays *ray, float x, float y, int checking)
{
	int	cx;
	int	cy;

	if (x <= 0 || (x / TILE_SIZE) >= game->max_line || y <= 0 || (y / TILE_SIZE) >= game->map_height)
		return (ret_zero(ray));
	cx = x / TILE_SIZE;
	cy = y / TILE_SIZE;
	if (ray->angle > 0 && ray->angle < 180 && checking == 0)
		cy -= 1;
	if (ray->angle > 90 && ray->angle < 270 && checking == 1)
		cx -= 1;
	if (cx < 0 || cx >= game->max_line)
	{
		// dprintf(2, "cx = %d map width = %d\n", cx, game->max_line);
		// dprintf(2, "cy = %d map height = %d\n", cy, game->map_height);
		return (ret_zero(ray));
	}
	if (cy < 0 || cy >= game->map_height)
	{
		// dprintf(2, "cx = %d map width = %d\n", cx, game->max_line);
		// dprintf(2, "cy = %d map height = %d\n", cy, game->map_height);
		return (ret_zero(ray));
	}
	ray->wall[0] = x;
	ray->wall[1] = y;
	// dprintf(2, "%f degrees : checking [%d][%d]\n", ray->angle, cx, cy);
	if (game->square_map[cy][cx] == '1')
		return (1);
	return (0);
}

void	loop_check_h(t_game *game, t_rays *ray, float theta)
{
	ray->y = TILE_SIZE;
	ray->x = ray->y / tanf(deg2rad(theta));
	fix_sign(ray);
	// dprintf(2, "%f degrees: horiz x-step = %f, horiz y_step = %f\n", ray->angle, ray->x, ray->y);
	while (!ray->h_wall_found)
	{
		// dprintf(2, "last checked position horiz: (%f, %f)\n", ray->h_check[0], ray->h_check[1]);
		ray->h_wall_found = check_l(game, ray, ray->h_check[0] + ray->x, ray->h_check[1] + ray->y, 0);
		// if (ray->wall[0] == 0 && ray->wall[1] == 0)
		// 	return ;
		ray->h_check[0] = ray->wall[0];
		ray->h_check[1] = ray->wall[1];
		if (ray->h_check[0] == 0 && ray->h_check[1] == 0)
			return ;
		// if (ray->h_wall_found == 1)
			// dprintf(2, "ray #%d: horizontal wall found at [%f][%f]\n", ray->id, ray->h_check[0], ray->h_check[1]);
	}
}

void	loop_check_v(t_game *game, t_rays *ray, float theta)
{
	ray->x = TILE_SIZE;
	ray->y = ray->x * tanf(deg2rad(theta));
	fix_sign(ray);
	// dprintf(2, "%f degrees: vert x-step = %f, vert y_step = %f\n", ray->angle, ray->x, ray->y);
	while (!ray->v_wall_found)
	{
		// dprintf(2, "last checked position vert: (%f, %f)\n", ray->v_check[0], ray->v_check[1]);
		ray->v_wall_found = check_l(game, ray, ray->v_check[0] + ray->x, ray->v_check[1] + ray->y, 1);

		// if (ray->wall[0] == 0 && ray->wall[1] == 0)
		// 	return ;
		ray->v_check[0] = ray->wall[0];
		ray->v_check[1] = ray->wall[1];
		if (ray->v_check[0] == 0 && ray->v_check[1] == 0)
			return ;
		// if (ray->v_wall_found == 1)
			// dprintf(2, "ray #%d: vertical wall found at [%f][%f]\n", ray->id, ray->v_check[0], ray->v_check[1]);
	}
}

void	first_check_h(t_game *game, t_rays *ray, float theta)
{
	if (ray->angle > 180 && ray->angle < 360)
		ray->y = TILE_SIZE - game->player.dy;
	else
		ray->y = game->player.dy;
	ray->x = ray->y / tanf(deg2rad(theta));
	// dprintf(2, "first check horizontal %d: \nangle: %f\nx: %f\ny: %f\n\n", ray->id, ray->angle, ray->x, ray->y);
	fix_sign(ray);
	ray->h_wall_found = check(game, ray, ray->x, ray->y, 0);
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
	ray->v_wall_found = check(game, ray, ray->x, ray->y, 1);
	ray->v_check[0] = ray->wall[0];
	ray->v_check[1] = ray->wall[1];
}

void	check_horizontal(t_game *game, t_rays *ray)
{
	float	theta;

	theta = ray->angle;
	if ((ray->angle > 90 && ray->angle < 180) || (ray->angle > 270 && ray->angle < 360))
		theta = 360 - ray->angle;
	// dprintf(2, "HORIZONTAL :::::: \n");
	first_check_h(game, ray, theta);
	// dprintf(2, "horizontal wall found? : %d\n", ray->h_wall_found);
	if (!ray->h_wall_found)
		loop_check_h(game, ray, theta);
	// else
		// dprintf(2, "%f : horiz found on first check at [%f][%f]\n", ray->angle, ray->h_check[0], ray->h_check[1]);
}

void	check_vertical(t_game *game, t_rays *ray)
{
	float	theta;

	theta = ray->angle;
	if ((ray->angle > 90 && ray->angle < 180) || (ray->angle > 270 && ray->angle < 360))
		theta = 360 - ray->angle;
	// dprintf(2, "VERTICAL :::::: \n");
	first_check_v(game, ray, theta);
	// dprintf(2, "vertical wall found? : %d\n", ray->v_wall_found);
	if (!ray->v_wall_found)
		loop_check_v(game, ray, theta);
	// else
		// dprintf(2, "%f : vert found on first check at [%f][%f]\n", ray->angle, ray->v_check[0], ray->v_check[1]);
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
	// dprintf(2, "%f degrees : Wall distance = %f\n", ray->angle, ray->dist);
	// dprintf(2, "wall coordinates: (%f, %f)\n", ray->wall[0], ray->wall[1]);
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
	while (x < wall_width * (ray->id + 1) && x <= (WIN_W + 1))
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

//REMEMBER TO DESTROY IMAGES
void	cast_rays(t_game *game)
{
	int	i;

	i = 0;
	create_rays(game);
	while (i < NUM_RAYS)
	{
		// printf("------------\nx: %d\ny: %d\ncx: %f\ncy: %f\ndx: %f\ndy: %f\ncarddir: %c\ndegrees: %f\n------------\n",
		// 	game->player.x, game->player.y, game->player.cx, game->player.cy, game->player.dx, 
		// 	game->player.dy, game->player.carddir, game->player.degrees);
		check_horizontal(game, &game->rays[i]);
		check_vertical(game, &game->rays[i]);
		if (horiz_wall(game, &game->rays[i]) && game->rays[i].h_wall_found)
		{
			fix_fisheye(game, &game->rays[i]);
			if (game->rays[i].angle >= 0 && game->rays[i].angle <= 180)
				print_wall(&game->rays[i], rgb_to_int(195, 0, 0), game->img); //north red
			else
				print_wall(&game->rays[i], rgb_to_int(150, 0, 195), game->img); //south purple
		}
		else if (game->rays[i].v_wall_found == 1)
		{
			fix_fisheye(game, &game->rays[i]);
			if (game->rays[i].angle >= 90 && game->rays[i].angle <= 270)
				print_wall(&game->rays[i], rgb_to_int(255, 205, 51), game->img); //west yellow
			else
				print_wall(&game->rays[i], rgb_to_int(255, 126, 51), game->img); //east orange
		}
		draw_line(game->player.cx, game->player.cy, game->rays[i].wall[0], game->rays[i].wall[1], game->img);
		i++;
	}
	// mlx_destroy_image(game->display.mlx, &game->img);
	free(game->rays);
}
