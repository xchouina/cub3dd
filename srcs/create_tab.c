#include "cub3d.h"

void	fd_create_tab_fd(t_game *game, int fd, char *argv)
{
	char	*str;
	char	*tmp;
	
	game->height_fd = 1;
	str = get_next_line(fd);
	tmp = ft_strtrim(str, "\n");
	free(str);
	// game->width_fd = ft_strlen(tmp);
	free(tmp);
	str = "";
	while (str)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		game->height_fd++;
		free(str);
	}
	close(fd);
	fd = open_fd(argv);
	fill_tab_fd(game, fd);
}

void	fill_tab_fd(t_game *game, int fd)
{
	int		i;

	i = 0;
	game->tab_fd = calloc(game->height_fd, sizeof(char *));
	if (game->tab_fd == NULL)
		ft_quit(fd);
	game->tab_fd[i] = get_next_line(fd);
	i++;
	while (i < game->height_fd)
	{
		char *tmp = get_next_line(fd);
		game->tab_fd[i] = ft_strdup(tmp);
		if (!game->tab_fd[i])
			break ;
		free(tmp);
		i++;
	}
	return ;
}

int	open_fd(char *argv)
{
	int fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		printf("fd error");
		return (1);
	}
	if (!ft_strendcmp(argv, ".cub"))
		ft_quit(fd);
	return (fd);
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
	fill_map_tab(game);
}

//protege les calloc si ya de la marde
void	fill_map_tab(t_game *game)
{
	int	i;

	i = 0;
	game->map = ft_calloc(game->map_height, sizeof(char *));
	//printf("map_start = %d\n", game->map_start);
	while (i < game->map_height - 1)
	{
		game->map[i] = ft_strdup(game->tab_fd[game->map_start]);
		//printf("game_map[%d] = %s\n", i, game->map[i]);
		game->map_start++;
		i++;
	}
}