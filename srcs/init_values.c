/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:48:06 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/19 13:05:56 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	split_space(char *f, t_game *game)
{
	f[0] = ft_split(f[0], ' ');
	f[1] = ft_split(f[1], ' ');
	f[2] = ft_split(f[2], ' ');
	
}

void	init_value(t_game *game)
{
	game->checker = 0;
	game->dir_no = 0;
	game->dir_so = 0;
	game->dir_we = 0;
	game->dir_ea = 0;
	game->dir_f = 0;
	game->dir_c = 0;
	game->doublons = 0;
	game->direction_complete = 0;
	game->square_map = NULL;
	game->tab_fd = NULL;
	game->map = NULL;
	game->image = 0;
	game->a_is_press = 0;
	game->d_is_press = 0;
	game->max = 0;
	game->check_last_q = 0;
	game->check_first_q = 0;
	game->first_q = 0;
	game->top_pixel = 0;
	game->bot_pixel = 0;
	game->tex_step = 0;
	game->checking = 0;
	game->text_doublons = 0;
}
