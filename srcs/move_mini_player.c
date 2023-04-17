#include "cub3d.h"

#define MOV_SP 1
#define ROT_SP 2

void	render(t_game *game)
{
	sky_n_ground(game);
	cast_rays(game);
	print_minimap(game);
}

void	w_press(t_game *game)
{
	if (game->square_map
		[(int)((game->player.cy + (game->delta_y * MOV_SP)) / TILE_SIZE)]
		[(int)((game->player.cx + (game->delta_x * MOV_SP)) / TILE_SIZE)]
			!= '1')
	{
		game->player.cx += game->delta_x * MOV_SP;
		game->player.cy += game->delta_y * MOV_SP;
		game->player.x = (int)game->player.cx / TILE_SIZE;
		game->player.y = (int)game->player.cy / TILE_SIZE;
		game->player.dx = game->player.cx - (game->player.x * TILE_SIZE);
		game->player.dy = game->player.cy - (game->player.y * TILE_SIZE);
		render(game);
	}
}

void	s_press(t_game *game)
{
	if (game->square_map
		[(int)((game->player.cy - (game->delta_y * MOV_SP)) / TILE_SIZE)]
		[(int)((game->player.cx - (game->delta_x * MOV_SP)) / TILE_SIZE)]
			!= '1')
	{
		game->player.cx -= game->delta_x * MOV_SP;
		game->player.cy -= game->delta_y * MOV_SP;
		game->player.x = (int)game->player.cx / TILE_SIZE;
		game->player.y = (int)game->player.cy / TILE_SIZE;
		game->player.dx = game->player.cx - (game->player.x * TILE_SIZE);
		game->player.dy = game->player.cy - (game->player.y * TILE_SIZE);
		render(game);
	}
}

void	d_press(t_game *game)
{
	game->player.degrees += ROT_SP;
	game->player.degrees = fixang(game->player.degrees);
	game->delta_x = cos(deg2rad(game->player.degrees));
	game->delta_y = -sin(deg2rad(game->player.degrees));
	render(game);
}

void	a_press(t_game *game)
{
	game->player.degrees -= ROT_SP;
	game->player.degrees = fixang(game->player.degrees);
	game->delta_x = cos(deg2rad(game->player.degrees));
	game->delta_y = -sin(deg2rad(game->player.degrees));
	render(game);
}
