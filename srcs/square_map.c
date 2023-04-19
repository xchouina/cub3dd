/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:38:44 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/19 09:57:08 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_first_q_of_line(int i, int j, t_game *game)
{
	game->first_q_of_line = game->max_line;
	while (j < game->max_line)
	{
		if (!ft_strchr(game->map[i], 'Q'))
			break ;
		while (game->map[i][j] != 'Q')
			j++;
		if (game->first_q_of_line > j)
			game->first_q_of_line = j;
		j = 0;
		i++;
	}
	game->first_q_of_line--;
}

int	find_max_line(int i, t_game *game)
{
	int	j;

	j = 0;
	while (game->map[i][j] != '\0')
	{
		if (game->map[i][j] == 'Q')
			game->check_first_q = 1;
		if (game->map[i][j] == 'Q' && j > game->max_line)
			game->max_line = j;
		j++;
	}
	j = 0;
	return (i);
}

int	find_first_line(int i, t_game *game)
{
	int	j;

	j = 0;
	while (!ft_strchr(game->map[i], 'Q'))
		i++;
	game->player.player_mm.position_y
		= game->player.player_mm.position_y - (i - 1);
	game->height_q = game->height_q - i;
	find_first_q_of_line(i, j, game);
	return (i - 1);
}

void	fill_square_map(int k, int i, int j, t_game *game)
{
	game->square_map[k]
		= ft_calloc(game->max_line - game->first_q_of_line, sizeof(char));
	while (++j < (game->max_line - game->first_q_of_line) - 1)
	{
		if (game->map[i][j + game->first_q_of_line] == ' '
			|| game->map[i][j + game->first_q_of_line] == '	'
			|| game->map[i][j + game->first_q_of_line] == '0'
			|| game->map[i][j + game->first_q_of_line] == '\n'
			|| game->map[i][j + game->first_q_of_line] == '1'
			|| game->map[i][j + game->first_q_of_line] == '\0')
			game->square_map[k][j] = '1';
		else if (game->map[i][j + game->first_q_of_line] == 'Q')
			game->square_map[k][j] = 'Q';
		else
			game->square_map[k][j] = '1';
		if (game->map[i][j + game->first_q_of_line] == '\n')
		{
			while (j < (game->max_line - game->first_q_of_line) - 1 || j < game->max_line - 1)
			{
				game->square_map[k][j] = '1';
				j++;
			}
		}
	}
	game->square_map[k][j] = '\n';
}

void	square_map(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = -1;
	k = -1;
	while (i < game->map_height)
	{
		find_max_line(i, game);
		if (!ft_strchr(game->map[i], 'Q') && game->check_first_q == 1)
			break ;
		i++;
	}
	game->height_q = i + 1;
	i = 0;
	i = find_first_line(i, game);
	game->max_line += 3;
	game->square_map = ft_calloc(game->height_q + 2, sizeof(char *));
	while (k < game->height_q)
	{
		fill_square_map(++k, i, j, game);
		i++;
	}
	max_map(game);
}
