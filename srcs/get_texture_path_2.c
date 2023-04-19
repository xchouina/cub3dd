/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_path_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:02:05 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/18 13:02:06 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_char(char **f)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (f[i])
	{
		while (f[i][j] != '\0')
		{
			if ((f[i][j] >= 33 && f[i][j] <= 47) || (f[i][j] >= 58 && f[i][j] <= 126))
			{
				printf("rgb not number\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	init_texture_tab(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->text[i].textures_path = NULL;
		i++;
	}
	game->text[i].textures_path = NULL;
}

void	split_colors(t_game *game)
{
	char	**f;
	char	**g;

	f = ft_split(game->ground_colors, ',');
	g = ft_split(game->ceiling_colors, ',');
	check_comma(game);
	check_char(f);
	check_char(g);
	if ((ft_atoi(f[0]) > 255) || (ft_atoi(f[1]) > 255) || (ft_atoi(f[2]) > 255) \
	|| (ft_atoi(g[0]) > 255) || (ft_atoi(g[1]) > 255) || (ft_atoi(g[2]) > 255))
	{
		dprintf(2, "rgb more than 255\n");
		ft_quit(game);
	}
	else if ((ft_atoi(f[0]) < 0) || (ft_atoi(f[1]) < 0) || (ft_atoi(f[2]) < 0) \
	|| (ft_atoi(g[0]) < 0) || (ft_atoi(g[1]) < 0) || (ft_atoi(g[2]) < 0))
	{
		dprintf(2, "rgb less than 255\n");
		ft_quit(game);
	}
	game->textures.couleur_floor = rgbtab_to_int(f);
	game->textures.couleur_sky = rgbtab_to_int(g);
	ft_free2d(f);
	ft_free2d(g);
}

void	get_floor_color(t_game *game, int i)
{
	int	j;
	int	len;
	int	start;

	j = 0;
	len = 0;
	if (ft_strncmp("F ", game->tab_fd[i], 2) == 0)
		j = 2;
	else if (ft_strncmp("F	", game->tab_fd[i], 2) == 0)
		j = 2;
	else
	{
		dprintf(2, "texture F error\n");
		ft_quit(game);
	}
	while (ft_iswhitespace(game->tab_fd[i][j]) == true)
		j++;
	start = j;
	while (game->tab_fd[i][j] != '\0' && game->tab_fd[i][j] != '\n')
	{
		j++;
		len++;
	}
	game->ground_colors = ft_substr(game->tab_fd[i], start, len);
}

void	get_roof_color(t_game *game, int i)
{
	int	j;
	int	len;
	int	start;

	j = 0;
	len = 0;
	if (ft_strncmp("C ", game->tab_fd[i], 2) == 0)
		j = 2;
	else if (ft_strncmp("C	", game->tab_fd[i], 2) == 0)
		j = 2;
	else
	{
		dprintf(2, "texture C error\n");
		ft_quit(game);
	}
	while (ft_iswhitespace(game->tab_fd[i][j]) == true)
		j++;
	start = j;
	while (game->tab_fd[i][j] != '\0' && game->tab_fd[i][j] != '\n')
	{
		j++;
		len++;
	}
	game->ceiling_colors = ft_substr(game->tab_fd[i], start, len);
}
