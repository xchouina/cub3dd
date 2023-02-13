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

	game = param;
	//mlx_delete_xpm42(game->sprite_player.xpm);
	// printf("press\n");
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		win_close(game);
	// if (keycode == 0)
	// 	left_move(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		printf("down\n");
		// mlx_delete_image()
		game->sprite_player.img->instances[0].y += 5;
	}
		// down_move(game);
	// if (keycode == 2)
	// 	right_move(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		printf("up\n");
		game->sprite_player.img->instances[0].y -= 5;	
	}
	if (game->image == 0)
	{
		mlx_image_to_window(game->mlx, game->sprite_player.img, (25 * game->player.player_mm.position_x), (25 * game->player.player_mm.position_y));
		game->image++;
		//printf("image\n");
	}
		// top_move(game);
	//mlx_image_to_window(game->mlx, game->player_mm, (25 * game->player.position_y), (25 * game->player.position_x));
	//printf("y = %d\n x = %d \n", game->player.position_y, game->player.position_x);
	// return (0);
}

// void	mlx_press_key(t_game *game)
// {
// 	// mlx_loop_hook(game->window, 2, 0, key_hook_move, game);
// 	mlx_loop_hook(game->mlx, &key_hook_move, game);
// 	// mlx_hook(game->window, 17, 0, win_close, game);
// }