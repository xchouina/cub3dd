#include "cub3d.h"

void	init_value(t_game *game)
{
	game->checker = 0;
	game->dir_NO = 0;
	game->dir_SO = 0;
	game->dir_WE = 0;
	game->dir_EA = 0;
	game->dir_F = 0;
	game->dir_C = 0;
	game->doublons = 0;
	game->direction_complete = 0;
	game->square_map = NULL;
	game->tab_fd = NULL;
	game->map = NULL;
	game->textures_tab = NULL;
	game->image = 0;
	game->a_is_press = 0;
	game->d_is_press = 0;
	game->max_line = 0;
	game->check_last_Q = 0;
	game->check_first_Q = 0;
	game->first_Q_of_line = 0;
}
