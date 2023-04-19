/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:56:12 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/18 10:56:14 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check(t_game *game, t_rays *ray, float x, float y)
{
	int		cx;
	int		cy;

	cx = (game->player.cx + x) / TILE_SIZE;
	cy = (game->player.cy + y) / TILE_SIZE;
	if (ray->angle >= 0 && ray->angle <= 180 && game->checking == 0)
		cy -= 1;
	if (ray->angle >= 90 && ray->angle <= 270 && game->checking == 1)
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

int	check_l(t_game *game, t_rays *ray, float x, float y)
{
	int	cx;
	int	cy;

	if (x <= 0 || (x / TILE_SIZE) >= game->map_x
		|| y <= 0 || (y / TILE_SIZE) >= game->map_y)
		return (ret_zero(ray));
	cx = x / TILE_SIZE;
	cy = y / TILE_SIZE;
	if (ray->angle > 0 && ray->angle < 180 && game->checking == 0)
		cy -= 1;
	if (ray->angle > 90 && ray->angle < 270 && game->checking == 1)
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
	game->checking = 0;
	while (!ray->h_wall_found)
	{
		ray->h_wall_found = check_l(game, ray, ray->h_check[0]
				+ ray->x, ray->h_check[1] + ray->y);
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
	game->checking = 1;
	while (!ray->v_wall_found)
	{
		ray->v_wall_found = check_l(game, ray, ray->v_check[0]
				+ ray->x, ray->v_check[1] + ray->y);
		ray->v_check[0] = ray->wall[0];
		ray->v_check[1] = ray->wall[1];
		if (ray->v_check[0] <= (float)0 && ray->v_check[1] <= (float)0)
		{
			ray->v_wall_found = 0;
			return ;
		}
	}
}
