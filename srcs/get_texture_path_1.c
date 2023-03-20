#include "cub3d.h"

void	get_text_p(t_game *game, int i, char *str_space, char *str_tab, int n)
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
		dprintf(2, "texture %serror\n", str_space);
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
	game->textures_tab[n] = ft_substr(game->tab_fd[i], start, len);
}

int	parsing_path(t_game *game)
{
	int	i;

	i = 0;
	init_texture_tab(game);
	while (i <= 6)
	{
		if (ft_strncmp("NO", game->tab_fd[i], 2) == 0)
			get_text_p(game, i, "NO ", "NO	", 0);
		if (ft_strncmp("SO", game->tab_fd[i], 2) == 0)
			get_text_p(game, i, "SO ", "SO	", 1);
		if (ft_strncmp("WE", game->tab_fd[i], 2) == 0)
			get_text_p(game, i, "WE ", "WE	", 2);
		if (ft_strncmp("EA", game->tab_fd[i], 2) == 0)
			get_text_p(game, i, "EA ", "EA	", 3);
		if (ft_strncmp("F", game->tab_fd[i], 1) == 0)
			get_floor_color(game, i);
		if (ft_strncmp("C", game->tab_fd[i], 1) == 0)
			get_roof_color(game, i);
		i++;
	}
	split_colors(game);
	game->textures_tab[i] = NULL;
	// if (game->checker == 1)
	// 	return (1);
	return (0);
}
