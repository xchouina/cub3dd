#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_pos	player;
	t_textures textures;
	int		fd;

	(void)player;
	(void)textures;
	fd = 0;
	if (argc != 2)
		return (1);
	if (parsing(&game, fd, argv[1]) == 1)
		return (1);
	// print_map(&game);
	starting_engine(&game);


	//print_tab_fd(&game);
	//print_player_pos(&game);
	return (0);
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

