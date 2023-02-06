#include "cub3d.h"

void	print_tab_textures(t_game *game)
{
	printf("			\033[1;34mtab_textures\033[0m							\n");
	int	i;

	i = 0;
	while (i <= 6)
	{
		printf("[%d]%s\n", i, game->textures_tab[i]);
		i++;
	}
	printf("\n\n");
}

void	print_tab_fd(t_game *tab)
{
	printf("			\033[1;34mfd_tab\033[0m							\n");
	int	i;

	i = 0;
	while (i < tab->height_fd)
	{
		printf("[%d]%s\n", i, tab->tab_fd[i]);
		i++;
	}
	printf("\n\n");
}

void	print_map(t_game *tab)
{
	printf("			\033[1;34mmap_tab\033[0m							\n");
	int	i;

	i = 0;
	while (i < tab->map_height - 1)
	{
		printf("[%d]%s\n", i, tab->map[i]);
		i++;
	}
	printf("\n\n");
}

void	print_player_pos(t_game *game)
{
	printf("			\033[1;34mplayer_position\033[0m							\n");
	printf("player position X = %d\n", game->player.position_x);
	printf("player position Y = %d\n", game->player.position_y);
	printf("\n\n");
}

void	print_color(t_game *game)
{
	printf("			\e[1;34mcolor\e[0m							\n");
	printf("colors floor = %d\n", game->textures.couleur_floor);
	printf("color ciel = %d\n", game->textures.couleur_sky);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_pos	player;
	t_textures textures;

	(void)player;
	(void)textures;
	game.fd = 0;
	if (argc != 2)
		return (1);
	if (parsing(&game, argv[1]) == 1)
		return (1);
	if (parsing_path(&game) == 1)
		return (1);
	// print_tab_textures(&game);
	// print_map(&game);
	starting_engine(&game);
	//print_tab_fd(&game);
	//print_map(&game);
	starting_engine(&game);
	mlx_close(&game);
	//print_tab_textures(&game);
	//print_player_pos(&game);
	//print_color(&game);
	ft_quit(&game);
	return (0);
}
