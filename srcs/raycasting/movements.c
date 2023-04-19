/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:56:15 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/18 11:57:51 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(t_game *game)
{
	sky_n_ground(game);
	cast_rays(game);
	print_minimap(game);
}

void	w_press(t_game *game)
{
	game->delta_x = cos(deg2rad(game->player.degrees));
	game->delta_y = -sin(deg2rad(game->player.degrees));
	if (game->square_map
		[(int)((game->player.cy + (game->delta_y * MOV_SP)) / TILE_SIZE)]
		[(int)((game->player.cx + (game->delta_x * MOV_SP)) / TILE_SIZE)]
			!= '1')
	{
		game->player.cx += game->delta_x * MOV_SP;
		game->player.cy += game->delta_y * MOV_SP;
		game->player.x = (int)game->player.cx / TILE_SIZE;
		game->player.y = (int)game->player.cy / TILE_SIZE;
		game->player.dx = game->player.cx - (game->player.x * TILE_SIZE);
		game->player.dy = game->player.cy - (game->player.y * TILE_SIZE);
		render(game);
	}
}

void	s_press(t_game *game)
{
	game->delta_x = cos(deg2rad(game->player.degrees));
	game->delta_y = -sin(deg2rad(game->player.degrees));
	if (game->square_map
		[(int)((game->player.cy - (game->delta_y * MOV_SP)) / TILE_SIZE)]
		[(int)((game->player.cx - (game->delta_x * MOV_SP)) / TILE_SIZE)]
			!= '1')
	{
		game->player.cx -= game->delta_x * MOV_SP;
		game->player.cy -= game->delta_y * MOV_SP;
		game->player.x = (int)game->player.cx / TILE_SIZE;
		game->player.y = (int)game->player.cy / TILE_SIZE;
		game->player.dx = game->player.cx - (game->player.x * TILE_SIZE);
		game->player.dy = game->player.cy - (game->player.y * TILE_SIZE);
		render(game);
	}
}

void	a_press(t_game *game)
{
	game->delta_x = cos(deg2rad(game->player.degrees + 90));
	game->delta_y = -sin(deg2rad(game->player.degrees + 90));
	if (game->square_map
		[(int)((game->player.cy - (game->delta_y * MOV_SP)) / TILE_SIZE)]
		[(int)((game->player.cx - (game->delta_x * MOV_SP)) / TILE_SIZE)]
			!= '1')
	{
		game->player.cx -= game->delta_x * MOV_SP;
		game->player.cy -= game->delta_y * MOV_SP;
		game->player.x = (int)game->player.cx / TILE_SIZE;
		game->player.y = (int)game->player.cy / TILE_SIZE;
		game->player.dx = game->player.cx - (game->player.x * TILE_SIZE);
		game->player.dy = game->player.cy - (game->player.y * TILE_SIZE);
		render(game);
	}
}

void	d_press(t_game *game)
{
	game->delta_x = cos(deg2rad(game->player.degrees - 90));
	game->delta_y = -sin(deg2rad(game->player.degrees - 90));
	if (game->square_map
		[(int)((game->player.cy - (game->delta_y * MOV_SP)) / TILE_SIZE)]
		[(int)((game->player.cx - (game->delta_x * MOV_SP)) / TILE_SIZE)]
			!= '1')
	{
		game->player.cx -= game->delta_x * MOV_SP;
		game->player.cy -= game->delta_y * MOV_SP;
		game->player.x = (int)game->player.cx / TILE_SIZE;
		game->player.y = (int)game->player.cy / TILE_SIZE;
		game->player.dx = game->player.cx - (game->player.x * TILE_SIZE);
		game->player.dy = game->player.cy - (game->player.y * TILE_SIZE);
		render(game);
	}
}
