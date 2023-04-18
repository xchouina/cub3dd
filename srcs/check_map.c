/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:51:57 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/18 12:53:31 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map(t_game *game)
{
	check_symbol_and_doublon(game);
	if (game->doublons == 0)
	{
		dprintf(2, "No player on map\n");
		ft_quit(game);
	}
	floodfill(game->player.player_mm.position_y, \
	game->player.player_mm.position_x, game);
}

void	check_symbol_and_doublon(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (ft_strchr("01 NSEW\n", game->map[i][j]) != NULL)
			{
				check_end_line(game, i, j);
				j++;
			}
			else
			{
				dprintf(2, "Error: Invalid symbol. (%c)\n", game->map[i][j]);
				ft_quit(game);
			}
		}
		i++;
	}
}

void	check_end_line(t_game *game, int i, int j)
{
	if (game->map[i][j] == '\n' && ft_strlen(game->map[i]) == 1)
	{
		dprintf(2, "Backslash_n needs to be at the end of the line\n");
		ft_quit(game);
	}
	if (game->map[i][j] == 'W' || game->map[i][j] == 'E' \
	|| game->map[i][j] == 'S' || game->map[i][j] == 'N')
	{
		game->player.player_mm.position_x = j;
		game->player.player_mm.position_y = i;
		if (game->doublons != 0)
		{
			dprintf(2, "Error: Invalid ammount of players on the map.\n");
			ft_quit(game);
		}
		else
			game->doublons = 1;
	}
}

void	outside_map(t_game *game)
{
	dprintf(2, "Failsafe: Player out of map's perimeters\n");
	ft_quit(game);
}

void	floodfill(int x, int y, t_game *game)
{
	if (game->map[x][y] < 37)
	{
		dprintf(2, "Error: Invalid map.\n");
		ft_quit(game);
	}
	if (game->map[x][y] == '0' || game->map[x][y] == 'N' || \
	game->map[x][y] == 'E' || game->map[x][y] == 'W' || game->map[x][y] == 'S')
	{
		if (x <= 0 || y <= 0)
			outside_map(game);
		if (game->map[x][y] == 'N' || game->map[x][y] == 'E' \
		|| game->map[x][y] == 'W' || game->map[x][y] == 'S')
			game->player.carddir = game->map[x][y];
		game->map[x][y] = 'Q';
	}
	else
		return ;
	floodfill(x - 1, y, game);
	floodfill(x, y + 1, game);
	floodfill(x + 1, y, game);
	floodfill(x, y - 1, game);
}
