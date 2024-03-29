/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:15:15 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/19 11:18:20 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_quit(t_game *game)
{
	if (game->fd != 0)
		close(game->fd);
	if (game->tab_fd != NULL)
		ft_free2d(game->tab_fd);
	if (game->map != NULL)
		ft_free2d(game->map);
	if (game->square_map != NULL)
		ft_free2d(game->square_map);
	exit(1);
}
