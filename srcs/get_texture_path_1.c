/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_path_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:01:34 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/19 12:44:36 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_error(char *path, t_game *game)
{
	dprintf(2, "Error: Texture \"%s\" is invalid.\n", path);
	ft_quit(game);
}

void	fill_text_path_in_order(t_game *game, int start, int len, int i)
{
	if (ft_strncmp("NO", game->tab_fd[i], 2) == 0)
	{
		game->text[0].textures_path = ft_substr(game->tab_fd[i], start, len);
		if (open(game->text[0].textures_path, O_RDONLY) == -1)
			texture_error("NO", game);
	}
	else if (ft_strncmp("SO", game->tab_fd[i], 2) == 0)
	{
		game->text[1].textures_path = ft_substr(game->tab_fd[i], start, len);
		if (open(game->text[1].textures_path, O_RDONLY) == -1)
			texture_error("SO", game);
	}
	else if (ft_strncmp("WE", game->tab_fd[i], 2) == 0)
	{
		game->text[2].textures_path = ft_substr(game->tab_fd[i], start, len);
		if (open(game->text[2].textures_path, O_RDONLY) == -1)
			texture_error("WE", game);
	}
	else if (ft_strncmp("EA", game->tab_fd[i], 2) == 0)
	{
		game->text[3].textures_path = ft_substr(game->tab_fd[i], start, len);
		if (open(game->text[3].textures_path, O_RDONLY) == -1)
			texture_error("EA", game);
	}
}

void	get_text_p(t_game *game, int i, char *str_space, char *str_tab)
{
	int	j;
	int	len;
	int	start;

	j = 0;
	len = 0;
	if (ft_strncmp(str_space, game->tab_fd[i], 3) == 0)
		j = 3;
	else if (ft_strncmp(str_tab, game->tab_fd[i], 3) == 0)
		j = 3;
	else
	{
		dprintf(2, "Error: Texture \"%s\" is invalid.\n", str_space);
		ft_quit(game);
	}
	while (ft_iswhitespace(game->tab_fd[i][j]) \
	== true && game->tab_fd[i][j] != '\n')
		j++;
	start = j;
	while (game->tab_fd[i][j] != '\0' && game->tab_fd[i][j] != '\n')
	{
		j++;
		len++;
	}
	fill_text_path_in_order(game, start, len, i);
}

void	compare(t_game *game, int i)
{
	if (ft_strncmp("NO", game->tab_fd[i], 2) == 0)
		get_text_p(game, i, "NO ", "NO	");
	if (ft_strncmp("SO", game->tab_fd[i], 2) == 0)
		get_text_p(game, i, "SO ", "SO	");
	if (ft_strncmp("WE", game->tab_fd[i], 2) == 0)
		get_text_p(game, i, "WE ", "WE	");
	if (ft_strncmp("EA", game->tab_fd[i], 2) == 0)
		get_text_p(game, i, "EA ", "EA	");
	if (ft_strncmp("F", game->tab_fd[i], 1) == 0)
		get_floor_color(game, i);
	if (ft_strncmp("C", game->tab_fd[i], 1) == 0)
		get_roof_color(game, i);
}

int	parsing_path(t_game *game)
{
	int	i;

	i = 0;
	init_texture_tab(game);
	while (i <= (game->map_start - game->map_height))
	{
		compare(game, i);
		i++;
	}
	split_colors(game);
	return (0);
}
