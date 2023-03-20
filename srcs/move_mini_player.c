#include "cub3d.h"

#define MOV_SP 1
#define ROT_SP 1

void	render(t_game *game)
{
	printf("------------------\nx: %d\ny: %d\ncx: %f\ncy: %f\ndx: %f\ndy: %f\ncarddir: %c\ndegrees: %f\n------------\n",
			game->player.x, game->player.y, game->player.cx, game->player.cy, game->player.dx, 
			game->player.dy, game->player.carddir, game->player.degrees);
	sky_n_ground(game);
	// drawRays2D(game);
	cast_rays(game);
	// map_creation(game);
	print_minimap(game);
	printf("Rendering...\n");
}

void	w_press(t_game *game)
{
	game->player.cx += game->delta_x * MOV_SP;
	game->player.cy += game->delta_y * MOV_SP;
	game->player.x = (int)game->player.cx / TILE_SIZE;
	game->player.y = (int)game->player.cy / TILE_SIZE;
	game->player.dx = game->player.cx - (game->player.x * TILE_SIZE);
	game->player.dy = game->player.cy - (game->player.y * TILE_SIZE);
	render(game);
}

void	s_press(t_game *game)
{
	game->player.cx -= game->delta_x * MOV_SP;
	game->player.cy -= game->delta_y * MOV_SP;
	game->player.dx = (int)game->player.cx % TILE_SIZE;
	game->player.dy = (int)game->player.cy % TILE_SIZE;
	game->player.x = (int)game->player.cx / TILE_SIZE;
	game->player.y = (int)game->player.cy / TILE_SIZE;
	render(game);
}

void	d_press(t_game *game)
{
	game->player.degrees += ROT_SP;
	game->player.degrees = FixAng(game->player.degrees);
	game->delta_x = cos(deg2rad(game->player.degrees));
	game->delta_y = -sin(deg2rad(game->player.degrees));
	render(game);
}

void	a_press(t_game *game)
{
	game->player.degrees -= ROT_SP;
	game->player.degrees = FixAng(game->player.degrees);
	game->delta_x = cos(deg2rad(game->player.degrees));
	game->delta_y = -sin(deg2rad(game->player.degrees));
	render(game);
}
