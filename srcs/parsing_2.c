#include "cub3d.h"

void	check_few_arg(t_game *game)
{
	if (game->dir_NO > 1 || game->dir_SO > 1 || game->dir_WE > 1\
	 || game->dir_EA > 1 || game->dir_F > 1 || game->dir_C > 1)
	{
		game->checker = 1;
		printf("to many arguments\n");
		ft_quit(game);
	}
	if (game->dir_NO < 1 || game->dir_SO < 1 || game->dir_WE < 1\
	 || game->dir_EA < 1 || game->dir_F < 1 || game->dir_C < 1)
	{
		game->checker = 1;
		printf("to few argument\n");
		ft_quit(game);
	}
}

void	fd_null(t_game *game)
{
	printf("fd = NULL\n");
	ft_quit(game);
}
// void	check_6_first_line(t_game *game)
// {
// 	int	all;
// 	int	i;

// 	all = 0;
// 	i = 0;
// 	if (game->tab_fd[i])
// 	if (all = 6)
// 		return ;
// }