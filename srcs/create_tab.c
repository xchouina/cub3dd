#include "cub3d.h"

void	open_fd(char *argv, t_game *game)
{

	game->fd = open(argv, O_RDONLY);
	if (game->fd == -1)
	{
		printf("fd error");
		ft_quit(game);
	}
	if (!ft_strendcmp(argv, ".cub"))
		ft_quit(game);
	return ;
}

void	fd_create_tab_map(t_game *game)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	game->map_height = 1;
	game->map_start = 0;
	while (i < game->height_fd)
	{
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
		j = 0;
		i++;
	}
}

//protege les calloc si ya de la marde
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

	i = 0;
	game->tab_fd = calloc(game->height_fd + 1, sizeof(char *));
	if (game->tab_fd == NULL)
		ft_quit(game);
	game->tab_fd[i] = get_next_line(game->fd);
	i++;
	while (i < game->height_fd)
	{
		char *tmp = get_next_line(game->fd);
		game->tab_fd[i] = ft_strdup(tmp);
		if (!game->tab_fd[i])
			break ;
		free(tmp);
		i++;
	}
	return ;
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

