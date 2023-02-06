#include "cub3d.h"

int	win_close(t_game *game)
{
	ft_quit(game);
	return (0);
}

int	key_hook_move(int keycode, t_game *game)
{
	if (keycode == 53)
		win_close(game);
	return (0);
}

void	mlx_close(t_game *game)
{
	mlx_hook(game->window, 2, 0, key_hook_move, game);
	mlx_hook(game->window, ON_DESTROY, 0, win_close, game->mlx);
}