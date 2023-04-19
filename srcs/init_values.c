/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:48:06 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/19 14:03:24 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	split_space(char **f)
{
	int		i;
	int		j;
	int		end;
	char	*tmp;

	i = 0;
	while (i < 3)
	{
		end = 0;
		j = 0;
		while ((f[i][j] <= 47) || (f[i][j] >= 58))
			j++;
		while (ft_isdigit(f[i][j]) == 1)
		{
			end++;
			j++;
		}
		tmp = ft_substr(f[i], j - end, end);
		free(f[i]);
		f[i] = tmp;
		i++;
	}
}

void    outside_map(t_game *game)
{
    dprintf(2, "Failsafe: Player out of map's perimeters\n");
    ft_quit(game);
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
