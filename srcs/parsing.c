/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:07:39 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/19 11:33:23 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_direction_2(t_game *game, int i)
{
	if (ft_strncmp("WE", game->tab_fd[i], 2) == 0)
		game->dir_we++;
	if (ft_strncmp("EA", game->tab_fd[i], 2) == 0)
		game->dir_ea++;
	if (ft_strncmp("F", game->tab_fd[i], 1) == 0)
		game->dir_f++;
	if (ft_strncmp("C", game->tab_fd[i], 1) == 0)
		game->dir_c++;
	check_direction_complete(game);
}

void	check_direction_complete(t_game *game)
{
	if (game->dir_no == 1 && game->dir_so == 1 && game->dir_we == 1 \
	&& game->dir_ea == 1 && game->dir_f == 1 && game->dir_c == 1)
		game->direction_complete = 1;
}

void	check_if_map_last(t_game *game, int i)
{
	int	j;

	j = 0;
	if (ft_strncmp("NO", game->tab_fd[i], 2) == 0
		|| ft_strncmp("SO", game->tab_fd[i], 2) == 0
		|| ft_strncmp("WE", game->tab_fd[i], 2) == 0
		|| ft_strncmp("EA", game->tab_fd[i], 2) == 0
		|| ft_strncmp("F", game->tab_fd[i], 1) == 0
		|| ft_strncmp("C", game->tab_fd[i], 1) == 0)
		return ;
	while (game->tab_fd[i][j] != '\0')
	{
		if (game->direction_complete == 1)
			return ;
		while (ft_iswhitespace(game->tab_fd[i][j]) == true
			&& game->tab_fd[i][j] != '\n')
			j++;
		if (game->tab_fd[i][j] == '1' || game->tab_fd[i][j] == '0')
		{
			dprintf(2, "map_not_last or direction problem/colors\n");
			ft_quit(game);
		}
		j++;
	}
	return ;
}

void	check_direction(t_game *game)
{
	int	i;

	i = 0;
	while (game->tab_fd[i] != NULL)
	{
		if (i == (game->height_fd - game->map_height) + 1)
		{
			check_few_arg(game);
			return ;
		}
		if (ft_strncmp(game->tab_fd[i], "NO", 2) == 0)
			game->dir_no++;
		if (ft_strncmp("SO", game->tab_fd[i], 2) == 0)
			game->dir_so++;
		check_direction_2(game, i);
		if (game->direction_complete != 1)
			check_if_map_last(game, i);
		i++;
		if (game->direction_complete == 1)
			break ;
	}
}

int	parsing(t_game *game, char *argv)
{
	init_value(game);
	open_fd(argv, game);
	fd_create_tab_fd(game, argv);
	fd_create_tab_map(game);
	game->map_height = 1;
	game->map_start = 0;
	fd_create_tab_map(game);
	check_direction(game);
	fill_map_tab(game);
	check_map(game);
	game->map_height--;
	square_map(game);
	game->player.player_mm.position_x
		= game->player.player_mm.position_x - (game->first_q);
	return (0);
}
