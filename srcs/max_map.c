/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:05:07 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/18 13:05:08 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_message(t_game *game)
{
	printf("Error: Map is too big.\n");
	ft_quit(game);
}

void	max_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->height_q)
	{
		j = 0;
		if (game->square_map[i][j] != '\0')
			break ;
		while (game->square_map[i][j] != '\n')
		{
			j++;
			if (j > 30)
				error_message(game);
		}
		i++;
		if (i > 20)
			error_message(game);
	}
}
