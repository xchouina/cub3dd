#include "cub3d.h"

void	init_texture_tab(t_game *game)
{
	game->textures_tab = ft_calloc(7, sizeof(char *));
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
		printf("texture F erreur");
		game->checker = 1;
		return ;
	}
	while (ft_iswhitespace(game->tab_fd[i][j]) == true)
		j++;
	start = j;
	while (game->tab_fd[i][j] != '\0' && game->tab_fd[i][j] != '\n')
	{
		j++;
		len++;
	}
	game->textures_tab[4] = ft_substr(game->tab_fd[i], start, len);
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
		printf("texture C erreur");
		game->checker = 1;
		return ;
	}
	while (ft_iswhitespace(game->tab_fd[i][j]) == true)
		j++;
	start = j;
	while (game->tab_fd[i][j] != '\0' && game->tab_fd[i][j] != '\n')
	{
		j++;
		len++;
	}
	game->textures_tab[5] = ft_substr(game->tab_fd[i], start, len);
}