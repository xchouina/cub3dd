#include "cub3d.h"

void	print_tab_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i <= 6)
	{
		printf("[%d]%s\n", i, game->textures_tab[i]);
		i++;
	}
}

void	print_tab_fd(t_game *tab)
{
	int	i;

	i = 0;
	while (i < tab->height_fd)
	{
		printf("[%d]%s", i, tab->tab_fd[i]);
		i++;
	}
}

void	print_map(t_game *tab)
{
	int	i;

	i = 0;
	while (i < tab->map_height - 1)
	{
		printf("[%d]%s\n", i, tab->map[i]);
		i++;
	}
}

void	print_player_pos(t_game *game)
{
	printf("player position X = %d\n", game->player.position_x);
	printf("player position Y = %d\n", game->player.position_y);
}

void	print_color(t_game *game)
{
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
	// init_raycast_assets(&game);
	// print_tab_textures(&game);
	// print_map(&game);
												// starting_engine(&game);
	//print_tab_fd(&game);
	//print_player_pos(&game);
	//print_color(&game);
	ft_quit(&game);
	return (0);
}
