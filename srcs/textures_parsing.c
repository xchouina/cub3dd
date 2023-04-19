/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:39:39 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/19 09:59:06 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_text_tab_colors(t_game *game, int i, uint32_t y, uint32_t x)
{
	uint32_t	j;
	uint32_t	k;
	uint32_t	m;
	uint32_t	f;
	int			l;

	f = x * 4;
	j = -1;
	k = 0;
	while (++j <= y)
	{
		l = -1;
		m = 0;
		game->text[i].colors[j]
			= ft_calloc(game->text[i].xpm->texture.width, sizeof(uint32_t));
		while (m < f)
		{
			game->text[i].colors[j][++l] = rgba_to_int
				(game->text[i].xpm->texture.pixels[k], game->text[i].xpm
					->texture.pixels[k + 1], game->text[i].xpm->texture
					.pixels[k + 2], game->text[i].xpm->texture.pixels[k + 3]);
			k += 4;
			m += 4;
		}
	}
}

void	parsing_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->fd = open(game->text[i].textures_path, O_RDONLY);
		if (game->fd == -1)
		{
			printf("%s error", game->text[i].textures_path);
			ft_quit(game);
		}
		close(game->fd);
		game->text[i].xpm = mlx_load_xpm42(game->text[i].textures_path);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		game->text[i].colors
			= ft_calloc(game->text[i].xpm->texture.height, sizeof(uint32_t *));
		fill_text_tab_colors(game, i, game->text[i].xpm->texture.height,
			game->text[i].xpm->texture.width);
		i++;
	}
}
