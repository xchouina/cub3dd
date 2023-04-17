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

int		ret_zero(t_rays *ray)
{
	ray->wall[0] = 0;
	ray->wall[1] = 0;
	return (0);
}

int		horiz_wall(t_game *game, t_rays *ray)
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

int 	get_color(t_text *text, int y, int x)
{
	if (x >= (int)text->xpm->texture.width)
		x = (int)text->xpm->texture.width - 1;
	if (y >= (int)text->xpm->texture.height)
		y = (int)text->xpm->texture.height - 1;
	return(text->colors[y][x]);
}

void    draw_wall_texture(t_game *game, int x, float y_start, float y_end, int i, float texture_offset, float tex_step)
{
    int     color;
    int     y;
    float   tex_pos;
    tex_pos = 0.0;
    y = y_start;
    while (y < y_end)
    {
        int tex_x = texture_offset * ((float)game->text[i].xpm->texture.width / (float)TILE_SIZE);
        int tex_y = (int)tex_pos;
        tex_pos += tex_step;
        color = get_color(&game->text[i], tex_y, tex_x);
        if (y > 0 && y < WIN_H)
            mlx_put_pixel(game->img, x, y, color);
        y++;
    }
}

void    print_wall(t_game *game, t_rays *ray, int x, int i)
{
    float   wall_height;
    float   wall_top_pixel;
    float   wall_bottom_pixel;
    float   texture_offset;
    float   tex_step;
    if (i == 0 || i == 1)
        texture_offset = (int)ray->wall[0] - ((int)ray->wall[0] / TILE_SIZE) * TILE_SIZE;
    else
        texture_offset = (int)ray->wall[1] - ((int)ray->wall[1] / TILE_SIZE) * TILE_SIZE;
    if (ray->dist <= 0.0001f)
        ray->dist = 0.0001f;
    wall_height = (5 / ray->dist) * WIN_H;
    wall_top_pixel = ((float)WIN_H - wall_height) / 2.0f;
    wall_bottom_pixel = wall_top_pixel + wall_height;
    tex_step = (float)game->text[i].xpm->texture.height / wall_height;
    draw_wall_texture(game, x, wall_top_pixel, wall_bottom_pixel, i, texture_offset, tex_step);
}

void    cast_rays(t_game *game)
{
    int i;
    int x;
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
        {
            fix_fisheye(game, &game->rays[i]);
            if (game->rays[i].angle >= 0 && game->rays[i].angle <= 180)
                print_wall(game, &game->rays[i], x, 0); //north
            else
                print_wall(game, &game->rays[i], x, 1); //south
        }
        else if (game->rays[i].v_wall_found == 1)
        {
            fix_fisheye(game, &game->rays[i]);
            if (game->rays[i].angle >= 90 && game->rays[i].angle <= 270)
                print_wall(game, &game->rays[i], x, 2); //west
            else
                print_wall(game, &game->rays[i], x, 3); //east
        }
        x++;
    }
    free(game->rays);
}
