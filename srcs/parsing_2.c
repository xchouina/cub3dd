/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:13:16 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/19 11:51:20 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_few_arg(t_game *game)
{
	if (game->dir_no > 1 || game->dir_so > 1 || game->dir_we > 1
		|| game->dir_ea > 1 || game->dir_f > 1 || game->dir_c > 1)
	{
		game->checker = 1;
		dprintf(2, "Error: Map has too many arguments.\n");
		ft_quit(game);
	}
	if (game->dir_no < 1 || game->dir_so < 1 || game->dir_we < 1
		|| game->dir_ea < 1 || game->dir_f < 1 || game->dir_c < 1)
	{
		game->checker = 1;
		dprintf(2, "Error: Map does not have enough arguments.\n");
		ft_quit(game);
	}
}

void	fd_null(t_game *game)
{
	dprintf(2, "Error: fd is NULL.\n");
	ft_quit(game);
}

void	check_after_comma(t_game *game, int i)
{
	if (ft_isdigit(game->ground_colors[i]) == 0)
	{
		dprintf(2, "Error: Invalid RGB values.\n");
		ft_quit(game);
	}
}

void	comma_check(int comma, t_game *game)
{
	if (comma != 2)
	{
		dprintf(2, "Error: Problem(s) with RGB commas.\n");
		ft_quit(game);
	}
}

void	check_comma(t_game *game)
{
	int	j;
	int	comma;

	j = -1;
	comma = 0;
	while (game->ground_colors[++j] != '\0')
	{
		if (game->ground_colors[j] == ',')
		{
			check_after_comma(game, 4);
			comma++;
		}
	}
	comma_check(comma, game);
	comma = 0;
	j = -1;
	while (game->ceiling_colors[++j] != '\0')
	{
		if (game->ceiling_colors[j] == ',')
		{
			check_after_comma(game, 4);
			comma++;
		}
	}
	comma_check(comma, game);
}
