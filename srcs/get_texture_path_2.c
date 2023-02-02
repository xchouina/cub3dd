#include "cub3d.h"

void	init_texture_tab(t_game *game)
{
	game->textures_tab = ft_calloc(8, sizeof(char *));
}

int	rgb_to_int(char **rgb)
{
	return ((ft_atoi(rgb[0]) << 16) + (ft_atoi(rgb[1]) << 8) + (ft_atoi(rgb[2])));
}

void	split_colors(t_game *game)
{
	char **f;
	char **g;

	check_comma(game);
	f = ft_split(game->textures_tab[4], ',');
	g = ft_split(game->textures_tab[5], ',');
	if ((ft_atoi(f[0]) > 255) || (ft_atoi(f[1]) > 255) || (ft_atoi(f[2]) > 255) \
	|| (ft_atoi(g[0]) > 255) || (ft_atoi(g[1]) > 255) || (ft_atoi(g[2]) > 255))
	{
		dprintf(2, "rgb more than 255");
		ft_quit(game);
	}
	game->textures.couleur_floor = rgb_to_int(f);
	game->textures.couleur_ciel = rgb_to_int(g);
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
		dprintf(2, "texture F erreur\n");
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
		dprintf(2, "texture C erreur\n");
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
	game->textures_tab[5] = ft_substr(game->tab_fd[i], start, len);
}