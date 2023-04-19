/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:57:05 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/19 12:10:24 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game			game;
	t_pos			player;

	(void)player;
	game.fd = 0;
	if (argc != 2)
	{
		printf("arg error");
		exit(1);
	}
	if (parsing(&game, argv[1]) == 1)
		return (1);
	if (parsing_path(&game) == 1)
		exit(1);
	parsing_textures(&game);
	starting_engine(&game);
	mlx_loop_hook(game.mlx, &key_hook_move, &game);
	mlx_loop(game.mlx);
	ft_quit(&game);
	return (0);
}
