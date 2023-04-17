#include "cub3d.h"

// void	parsing_textures_no(t_game *game)
// {
// 	int		i;
// 	int		j;
// 	char	*tmp;

// 	i = 0;
// 	j = 0;
// 	game->text.fill_tab_no = ft_calloc(551, sizeof(char *));
// 	game->fd = open(game->text.textures_tab[0], O_RDONLY);
// 	// printf("texturePath_no = %s\n", game->text.textures_tab[0]);
// 	if (!game->fd)
// 		ft_quit(game);
// 	while (i < 262)
// 	{
// 		tmp = get_next_line(game->fd);
// 		free(tmp);
// 		i++;
// 	}
// 	while (i < 812)
// 	{
// 		tmp = get_next_line(game->fd);
// 		game->text.fill_tab_no[j] = ft_strdup(tmp);
// 		// printf("text tab_so = %s\n", game->text.fill_tab_no[j]);
// 		if (!game->text.fill_tab_no[j])
// 			break ;
// 		free(tmp);
// 		j++;
// 		i++;
// 	}
// 	close(game->fd);
// }

// void	parsing_textures_so(t_game *game)
// {
// 	int		i;
// 	int		j;
// 	char	*tmp;

// 	i = 0;
// 	j = 0;
// 	game->text.fill_tab_so = ft_calloc(269, sizeof(char *));
// 	game->fd = open(game->text.textures_tab[1], O_RDONLY);
// 	// printf("texturePath_so = %s\n", game->text.textures_tab[1]);
// 	if (!game->fd)
// 		ft_quit(game);
// 	while (i < 262)
// 	{
// 		tmp = get_next_line(game->fd);
// 		free(tmp);
// 		i++;
// 	}
// 	while (i < 629)
// 	{
// 		tmp = get_next_line(game->fd);
// 		game->text.fill_tab_so[j] = ft_strdup(tmp);
// 		// printf("text tab_so = %s\n", game->text.fill_tab_so[j]);
// 		if (!game->text.fill_tab_so[j])
// 			break ;
// 		free(tmp);
// 		j++;
// 		i++;
// 	}
// 	close(game->fd);
// }

// void	parsing_textures_we(t_game *game)
// {
// 	int		i;
// 	int		j;
// 	char	*tmp;

// 	i = 0;
// 	j = 0;
// 	game->text.fill_tab_we = ft_calloc(195, sizeof(char *));
// 	game->fd = open(game->text.textures_tab[2], O_RDONLY);
// 	// printf("texturePath_we = %s\n", game->text.textures_tab[2]);
// 	if (!game->fd)
// 		ft_quit(game);
// 	while (i < 262)
// 	{
// 		tmp = get_next_line(game->fd);
// 		free(tmp);
// 		i++;
// 	}
// 	while (i < 456)
// 	{
// 		tmp = get_next_line(game->fd);
// 		game->text.fill_tab_we[j] = ft_strdup(tmp);
// 		// printf("text tab_we = %s\n", game->text.fill_tab_we[j]);
// 		if (!game->text.fill_tab_we[j])
// 			break ;
// 		free(tmp);
// 		j++;
// 		i++;
// 	}
// 	close(game->fd);
// }

// void	parsing_textures_ea(t_game *game)
// {
// 	int		i;
// 	int		j;
// 	char	*tmp;

// 	i = 0;
// 	j = 0;
// 	game->text.fill_tab_ea = ft_calloc(900, sizeof(char *));
// 	game->fd = open(game->text.textures_tab[3], O_RDONLY);
// 	// printf("texturePath_ea = %s\n", game->text.textures_tab[3]);
// 	if (!game->fd)
// 		ft_quit(game);
// 	while (i < 262)
// 	{
// 		tmp = get_next_line(game->fd);
// 		free(tmp);
// 		i++;
// 	}
// 	while (i < 1162)
// 	{
// 		tmp = get_next_line(game->fd);
// 		game->text.fill_tab_ea[j] = ft_strdup(tmp);
// 		// printf("text tab_ea = %s\n", game->text.fill_tab_ea[j]);
// 		if (!game->text.fill_tab_ea[j])
// 			break ;
// 		free(tmp);
// 		j++;
// 		i++;
// 	}
// 	close(game->fd);
// }

// void	tab_colors_texture_no(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	printf("texture_tab[%d] = %s\n", i, game->text[0].fill_tab);
// }

void	fill_text_tab_colors(t_game *game, int i, uint32_t y, uint32_t x)
{
	uint32_t	j;
	uint32_t	k;
	uint32_t	m;
	int			l;
	uint32_t			f;

	f = x * 4;

	m = 0;
	j = 0;
	k = 0;
	l = 0;
	while (j <= y)
	{
		//printf("texture_width = %d\n", game->text[i].xpm->texture.width);
		game->text[i].colors[j] = ft_calloc(game->text[i].xpm->texture.width, sizeof(uint32_t));
		while (m < f)
		{
			// printf("%p--%p--%p--%p", game->text[i].xpm->texture.pixels[k], game->text[i].xpm->texture.pixels[k + 1], game->text[i].xpm->texture.pixels[k + 2], game->text[i].xpm->texture.pixels[k + 3]);
			game->text[i].colors[j][l] = rgba_to_int(game->text[i].xpm->texture.pixels[k], \
			game->text[i].xpm->texture.pixels[k + 1], game->text[i].xpm->texture.pixels[k + 2], \
			game->text[i].xpm->texture.pixels[k + 3]);
			//printf("%u\n", game->text[i].colors[j][l]);
			k += 4;
			m += 4;
			l++;
		}
		// printf("k = %d\n", k);
		// printf("x = %d\n", x);
		// printf("j = %d\n", j);
		l = 0;
		m = 0;
		j++;
	}
}

void parsing_textures(t_game *game)
{
	int	i;
	i = 0;
	while (i < 4)
	{
		// printf("path = %s\n", game->text[i].textures_path);
		game->text[i].xpm = mlx_load_xpm42(game->text[i].textures_path);
		//print_colors_mlx42(game, i);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		game->text[i].colors = ft_calloc(game->text[i].xpm->texture.height, sizeof(uint32_t *));
		fill_text_tab_colors(game, i, game->text[i].xpm->texture.height, game->text[i].xpm->texture.width);
		// printf("separeted\n");
		//print_colors_tab(game, i);
		i++;
	// printf("HERE\n");
	}

	// printf("");
	// parsing_colors_no(game);
	// parsing_colors_so(game);
	// parsing_colors_we(game);
	// parsing_colors_ea(game);
	// parsing_textures_no(game);
	// parsing_textures_so(game);
	// parsing_textures_we(game);
	// parsing_textures_ea(game);
	// tab_colors_texture_no(game);
	// ne pas hard coder faire un while pour crer les tab et prendre des image pas plus grosse que 100/100
}
