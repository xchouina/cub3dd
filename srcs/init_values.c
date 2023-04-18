/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:48:06 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/18 12:48:08 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	game->max_line = 0;
	game->check_last_q = 0;
	game->check_first_q = 0;
	game->first_q_of_line = 0;
	game->top_pixel = 0;
	game->bot_pixel = 0;
	game->tex_step = 0;
	game->checking = 0;
}
