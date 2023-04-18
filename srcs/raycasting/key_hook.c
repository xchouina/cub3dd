/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:59:14 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/18 11:59:19 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	win_close(t_game *game)
{
	printf("exit\n");
	mlx_close_window(game->mlx);
	ft_quit(game);
	mlx_terminate(game->mlx);
	exit (0);
}

void	key_hook_move(void *param)
{
	t_game	*game;
	int		i;

	i = 0;
	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		win_close(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		s_press(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		w_press(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		d_press(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		a_press(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		left_press(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		right_press(game);
}

void	right_press(t_game *game)
{
	game->player.degrees += ROT_SP;
	game->player.degrees = fixang(game->player.degrees);
	game->delta_x = cos(deg2rad(game->player.degrees));
	game->delta_y = -sin(deg2rad(game->player.degrees));
	render(game);
}

void	left_press(t_game *game)
{
	game->player.degrees -= ROT_SP;
	game->player.degrees = fixang(game->player.degrees);
	game->delta_x = cos(deg2rad(game->player.degrees));
	game->delta_y = -sin(deg2rad(game->player.degrees));
	render(game);
}
