/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:00:19 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/19 13:08:29 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_fd(char *argv, t_game *game)
{
	game->fd = open(argv, O_RDONLY);
	if (game->fd == -1)
	{
		dprintf(2, "Error: Invalid file descriptor.\n");
		exit(1);
	}
	if (!ft_strendcmp(argv, ".cub"))
	{
		dprintf(2, "Error: Map's file must be a \".cub\"\n");
		exit(1);
	}
	return ;
}

void	fd_create_tab_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->map_height = 1;
	game->map_start = 0;
	while (++i < game->height_fd)
	{
		j = 0;
		while (game->tab_fd[i][j] != '\0')
		{
			if (ft_strchr("NOSWEA", game->tab_fd[i][j]) != NULL)
				break ;
			if (ft_strchr("FC", game->tab_fd[i][j]) != NULL)
				break ;
			if (ft_strchr("10", game->tab_fd[i][j]) != NULL)
			{
				if (game->map_start == 0)
					game->map_start = i;
				game->map_height++;
				break ;
			}
			j++;
		}
	}
}

void	fill_map_tab(t_game *game)
{
	int	i;

	i = 0;
	game->map = ft_calloc(game->map_height, sizeof(char *));
	while (i < game->map_height - 1)
	{
		game->map[i] = ft_strdup(game->tab_fd[game->map_start]);
		game->map_start++;
		i++;
	}
}

void	fill_tab_fd(t_game *game)
{
	int		i;
	char	*tmp;

	i = 0;
	game->tab_fd = calloc(game->height_fd + 1, sizeof(char *));
	if (game->tab_fd == NULL)
		ft_quit(game);
	game->tab_fd[i] = get_next_line(game->fd);
	i++;
	while (i < game->height_fd)
	{
		tmp = get_next_line(game->fd);
		game->tab_fd[i] = ft_strdup(tmp);
		if (!game->tab_fd[i])
			break ;
		free(tmp);
		i++;
	}
	return ;
}

void	outside_map(t_game *game)
{
	dprintf(2, "Failsafe: Player out of map's perimeters\n");
	ft_quit(game);
}

void	fd_create_tab_fd(t_game *game, char *argv)
{
	char	*str;
	char	*tmp;

	game->height_fd = 1;
	str = get_next_line(game->fd);
	if (str == NULL)
		fd_null(game);
	tmp = ft_strtrim(str, "\n");
	free(str);
	free(tmp);
	str = "";
	while (str)
	{
		str = get_next_line(game->fd);
		if (!str)
			break ;
		game->height_fd++;
		free(str);
	}
	close(game->fd);
	open_fd(argv, game);
	fill_tab_fd(game);
	return ;
}
