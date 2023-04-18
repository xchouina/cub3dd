/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:56:07 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/18 10:56:11 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	horiz_wall(t_game *game, t_rays *ray)
{
	float	h_dist;
	float	v_dist;

	h_dist = sqrtf(powf(ray->h_check[1] - game->player.cy, 2)
			+ powf(ray->h_check[0] - game->player.cx, 2));
	v_dist = sqrtf(powf(ray->v_check[1] - game->player.cy, 2)
			+ powf(ray->v_check[0] - game->player.cx, 2));
	if ((!ray->v_wall_found || h_dist < v_dist)
		&& (ray->h_check[1] && ray->h_check[0]))
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
	ray->dist = roundf((ray->dist * cosf(deg2rad(ray->angle
						- game->player.degrees)) * 100000)) / 100000;
}

int	get_color(t_text *text, int y, int x)
{
	if (x >= (int)text->xpm->texture.width)
		x = (int)text->xpm->texture.width - 1;
	if (y >= (int)text->xpm->texture.height)
		y = (int)text->xpm->texture.height - 1;
	return (text->colors[y][x]);
}

void	draw_wall_texture(t_game *game, int x, int i, float texture_offset)
{
	int		color;
	int		y;
	float	tex_pos;
	int		tex_y;
	int		tex_x;

	tex_pos = 0.0;
	y = game->top_pixel;
	while (y < game->bot_pixel)
	{
		tex_x = texture_offset * ((float)game->text[i].xpm->texture.width
				/ (float)TILE_SIZE);
		tex_y = (int)tex_pos;
		tex_pos += game->tex_step;
		color = get_color(&game->text[i], tex_y, tex_x);
		if (y > 0 && y < WIN_H)
			mlx_put_pixel(game->img, x, y, color);
		y++;
	}
}

void	print_wall(t_game *game, t_rays *ray, int x, int i)
{
	float	wall_height;
	float	texture_offset;

	if (i == 0 || i == 1)
		texture_offset = (int)ray->wall[0]
			- ((int)ray->wall[0] / TILE_SIZE) * TILE_SIZE;
	else
		texture_offset = (int)ray->wall[1]
			- ((int)ray->wall[1] / TILE_SIZE) * TILE_SIZE;
	if (ray->dist <= 1.0f)
		ray->dist = 1.0f;
	wall_height = (5 / ray->dist) * WIN_H;
	game->top_pixel = ((float)WIN_H - wall_height) / 2.0f;
	game->bot_pixel = game->top_pixel + wall_height;
	game->tex_step = (float)game->text[i].xpm->texture.height / wall_height;
	draw_wall_texture(game, x, i, texture_offset);
}
