#include "cub3d.h"

void	w_press(t_game *game)
{
	int	i;

	i = 0;
	game->sprite_player.img->instances[0].y -= 1;
	// while (i < 50 && ((25 * game->player.player_mm.position_y) + 12.5) - i >= 0)
	// {
	// 	printf("game_pos_x = %f\n", 25 * game->player.player_mm.position_x);
	// 	printf("game_pos_y = %f\n", (game->player.player_mm.position_y));
	// 	mlx_put_pixel(game->img, 25 * game->player.player_mm.position_x, ((25 * game->player.player_mm.position_y) + 12.5) - i, 0xFF0000);
	// 	i++;
	// }
	//game->player.player_mm.position_y -= 1;
}

void	s_press(t_game *game)
{
	game->sprite_player.img->instances[0].y += 1;
}

void	d_press(t_game *game)
{
	(void)game;
}

void	a_press(t_game *game)
{
	(void)game;
}

// mlx_image_to_window(game->mlx, game->sprite_player.img, (25 * game->player.player_mm.position_x), (25 * game->player.player_mm.position_y));