/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:56:22 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/19 11:36:02 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_cube(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= TILE_SIZE)
	{
		j = 0;
		while (j <= TILE_SIZE)
		{
			if (i % TILE_SIZE != 0 || j % TILE_SIZE != 0)
				mlx_put_pixel(game->img, ((x * TILE_SIZE) + j),
					((y * TILE_SIZE) + i), color);
			if (i % TILE_SIZE == 0 || j % TILE_SIZE == 0)
				mlx_put_pixel(game->img, ((x * TILE_SIZE) + j),
					((y * TILE_SIZE) + i), 0xFFFFFF);
			j++;
		}
		i++;
	}
}

void	print_player(t_game *game, int cx, int cy)
{
	int	i;
	int	j;
	int	size;

	size = 2;
	i = cy - size;
	while (i < cy + size)
	{
		j = cx - size;
		while (j < cx + size)
		{
			mlx_put_pixel(game->img, j, i, 0x0000FF);
			j++;
		}
		i++;
	}
}

void	print_minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y <= game->height_q)
	{
		x = 0;
		while (x < game->max)
		{
			if (game->square_map[y][x] == '1')
				put_cube(game, x, y, rgb_to_int(100, 103, 100));
			else if (game->square_map[y][x] == 'Q')
				put_cube(game, x, y, rgb_to_int(195, 3, 250));
			x++;
		}
		y++;
	}
	print_player(game, game->player.cx, game->player.cy);
}
