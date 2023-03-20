#include "cub3d.h"

int	win_close(t_game *game)
{
	printf("exit\n");
	mlx_close_window(game->mlx);
	ft_quit(game);
	mlx_terminate(game->mlx);
	exit (0);
}

void	key_hook_move(void *param)
{
	t_game	*game;
	int	i;

	i = 0;
	game = (t_game*)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		win_close(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		s_press(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		w_press(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		d_press(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		a_press(game);
}
