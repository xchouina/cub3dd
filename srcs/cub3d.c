/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:57:05 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/19 12:54:26 by xchouina         ###   ########.fr       */
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
		printf("Error: Invalid ammount of arguments.\n");
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
