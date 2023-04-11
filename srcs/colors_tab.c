#include "cub3d.h"

// void	parsing_colors_we(t_game *game)
// {
// 	int		i;
// 	int		j;
// 	char	*tmp;

// 	i = 0;
// 	j = 0;
// 	game->text.colors_we = ft_calloc(257, sizeof(char *));
// 	game->fd = open(game->text.textures_tab[2], O_RDONLY);
// 	// printf("texturePath_we = %s\n", game->text.textures_tab[2]);
// 	if (!game->fd)
// 		ft_quit(game);
// 	while (i < 4)
// 	{
// 		tmp = get_next_line(game->fd);
// 		free(tmp);
// 		i++;
// 	}
// 	while (j < 256)
// 	{
// 		tmp = get_next_line(game->fd);
// 		game->text.colors_we[j] = ft_strdup(tmp);
// 		// printf("text tab collors_we = %s\n", game->text.colors_we[j]);
// 		if (!game->text.colors_we[j])
// 			break ;
// 		free(tmp);
// 		j++;
// 	}
// 	close(game->fd);
// }

// void	parsing_colors_no(t_game *game)
// {
// 	int		i;
// 	int		j;
// 	char	*tmp;

// 	i = 0;
// 	j = 0;
// 	game->text.colors_no = ft_calloc(257, sizeof(char *));
// 	game->fd = open(game->text.textures_tab[0], O_RDONLY);
// 	// printf("texturePath_no = %s\n", game->text.textures_tab[0]);
// 	if (!game->fd)
// 		ft_quit(game);
// 	while (i < 4)
// 	{
// 		tmp = get_next_line(game->fd);
// 		free(tmp);
// 		i++;
// 	}
// 	while (j < 256)
// 	{
// 		tmp = get_next_line(game->fd);
// 		game->text.colors_no[j] = ft_strdup(tmp);
// 		// printf("text tab collors_no = %s\n", game->text.colors_no[j]);
// 		if (!game->text.colors_no[j])
// 			break ;
// 		free(tmp);
// 		j++;
// 	}
// 	close(game->fd);
// }

// void	parsing_colors_ea(t_game *game)
// {
// 	int		i;
// 	int		j;
// 	char	*tmp;

// 	i = 0;
// 	j = 0;
// 	game->text.colors_ea = ft_calloc(257, sizeof(char *));
// 	game->fd = open(game->text.textures_tab[3], O_RDONLY);
// 	// printf("texturePath_ea = %s\n", game->text.textures_tab[3]);
// 	if (!game->fd)
// 		ft_quit(game);
// 	while (i < 4)
// 	{
// 		tmp = get_next_line(game->fd);
// 		free(tmp);
// 		i++;
// 	}
// 	while (j < 256)
// 	{
// 		tmp = get_next_line(game->fd);
// 		game->text.colors_ea[j] = ft_strdup(tmp);
// 		// printf("text tab collors_ea = %s\n", game->text.colors_ea[j]);
// 		if (!game->text.colors_ea[j])
// 			break ;
// 		free(tmp);
// 		j++;
// 	}
// 	close(game->fd);
// }


// void	parsing_colors_so(t_game *game)
// {
// 	int		i;
// 	int		j;
// 	char	*tmp;

// 	i = 0;
// 	j = 0;
// 	game->text.colors_so = ft_calloc(257, sizeof(char *));
// 	game->fd = open(game->text.textures_tab[1], O_RDONLY);
// 	// printf("texturePath_so = %s\n", game->text.textures_tab[1]);
// 	if (!game->fd)
// 		ft_quit(game);
// 	while (i < 4)
// 	{
// 		tmp = get_next_line(game->fd);
// 		free(tmp);
// 		i++;
// 	}
// 	while (j < 256)
// 	{
// 		tmp = get_next_line(game->fd);
// 		game->text.colors_so[j] = ft_strdup(tmp);
// 		// printf("text tab collors_so = %s\n", game->text.colors_so[j]);
// 		if (!game->text.colors_so[j])
// 			break ;
// 		free(tmp);
// 		j++;
// 	}
// 	close(game->fd);
// }