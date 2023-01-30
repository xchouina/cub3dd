#include "cub3d.h"

void	check_few_arg(t_game *game)
{
	if (game->dir_NO > 1 || game->dir_SO > 1 || game->dir_WE > 1\
	 || game->dir_EA > 1 || game->dir_F > 1 || game->dir_C > 1)
	{
		game->checker = 1;
		printf("to many arguments\n");
		return ;
	}
	if (game->dir_NO < 1 || game->dir_SO < 1 || game->dir_WE < 1\
	 || game->dir_EA < 1 || game->dir_F < 1 || game->dir_C < 1)
	{
		game->checker = 1;
		printf("to few argument\n");
		return ;
	}
}