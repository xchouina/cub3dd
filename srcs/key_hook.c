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
	game = param;
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

// void	mlx_press_key(t_game *game)
// {
// 	// mlx_loop_hook(game->window, 2, 0, key_hook_move, game);
// 	mlx_loop_hook(game->mlx, &key_hook_move, game);
// 	// mlx_hook(game->window, 17, 0, win_close, game);
// }