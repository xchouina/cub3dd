#include "cub3d.h"

void	get_text_path(t_game *game, int i, char *str_space, char *str_tab, int n)
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
		printf("texture %serreur", str_space);
		game->checker = 1;
		return ;
	}
	while (ft_iswhitespace(game->tab_fd[i][j]) == true && game->tab_fd[i][j] != '\n')
		j++;
	start = j;
	while (game->tab_fd[i][j] != '\0' && game->tab_fd[i][j] != '\n')
	{
		j++;
		len++;
	}
	game->textures_tab[n] = ft_substr(game->tab_fd[i], start, len);
}

// void	get_text_path_so(t_game *game, int i)
// {
// 	int	j;
// 	int	len;
// 	int	start;

// 	j = 0;
// 	len = 0;
// 	if (ft_strncmp("SO ", game->tab_fd[i], 3) == 0)
// 		j = 3;
// 	else if (ft_strncmp("SO	", game->tab_fd[i], 3) == 0)
// 		j = 3;
// 	else
// 	{
// 		printf("texture SO erreur");
// 		game->checker = 1;
// 		return ;
// 	}
// 	while (ft_iswhitespace(game->tab_fd[i][j]) == true && game->tab_fd[i][j] != '\n')
// 		j++;
// 	start = j;
// 	while (game->tab_fd[i][j] != '\0' && game->tab_fd[i][j] != '\n')
// 	{
// 		j++;
// 		len++;
// 	}
// 	game->textures_tab[1] = ft_substr(game->tab_fd[i], start, len);
// }

// void	get_text_path_we(t_game *game, int i)
// {
// 	int	j;
// 	int	len;
// 	int	start;

// 	j = 0;
// 	len = 0;
// 	if (ft_strncmp("WE ", game->tab_fd[i], 3) == 0)
// 		j = 3;
// 	else if (ft_strncmp("WE	", game->tab_fd[i], 3) == 0)
// 		j = 3;
// 	else
// 	{
// 		printf("texture WE erreur");
// 		game->checker = 1;
// 		return ;
// 	}
// 	while (ft_iswhitespace(game->tab_fd[i][j]) == true && game->tab_fd[i][j] != '\n')
// 		j++;
// 	start = j;
// 	while (game->tab_fd[i][j] != '\0' && game->tab_fd[i][j] != '\n')
// 	{
// 		j++;
// 		len++;
// 	}
// 	game->textures_tab[2] = ft_substr(game->tab_fd[i], start, len);
// }

// void	get_text_path_ea(t_game *game, int i)
// {
// 	int	j;
// 	int	len;

// 	j = 0;
// 	len = 0;
// 	if (ft_strncmp("EA ", game->tab_fd[i], 3) == 0)
// 		j = 3;
// 	else if (ft_strncmp("EA	", game->tab_fd[i], 3) == 0)
// 		j = 3;
// 	else
// 	{
// 		printf("texture EA erreur");
// 		game->checker = 1;
// 		return ;
// 	}
// 	while (ft_iswhitespace(game->tab_fd[i][j]) == true)
// 		j++;
// 	while (game->tab_fd[i][j] != '\0' || game->tab_fd[i][j] != '\n')
// 	{
// 		j++;
// 		len++;
// 	}
// 	game->textures_tab[3] = ft_substr(game->tab_fd[i], j, len);
// }

int	parsing_path(t_game *game)
{
	int	i;

	i = 0;
	init_texture_tab(game);
	while (i <= 6)
	{
		if (ft_strncmp("NO", game->tab_fd[i], 2) == 0)
			get_text_path(game, i, "NO ", "NO	", 0);
		if (ft_strncmp("SO", game->tab_fd[i], 2) == 0)
			get_text_path(game, i, "SO ", "SO	", 1);
		if (ft_strncmp("WE", game->tab_fd[i], 2) == 0)
			get_text_path(game, i, "WE ", "WE	", 2);
		if (ft_strncmp("EA", game->tab_fd[i], 2) == 0)
			get_text_path(game, i, "EA ", "EA	", 3);
		if (ft_strncmp("F", game->tab_fd[i], 1) == 0)
			get_floor_color(game, i);
		if (ft_strncmp("C", game->tab_fd[i], 1) == 0)
			get_roof_color(game, i);
		i++;
	}
	game->tab_fd[i] = NULL;
	if (game->checker == 1)
		return (1);
	return (0);
}