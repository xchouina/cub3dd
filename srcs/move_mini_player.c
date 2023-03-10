#include "cub3d.h"

void	w_press(t_game *game)
{
	game->sprite_player.img->instances[0].x += game->delta_x * 3;
	game->sprite_player.img->instances[0].y += game->delta_y * 3;
	// drawRays2D(game);
	
}

void	s_press(t_game *game)
{
	game->sprite_player.img->instances[0].x -= game->delta_x * 3;
	game->sprite_player.img->instances[0].y -= game->delta_y * 3;
	// drawRays2D(game);
}

void	d_press(t_game *game)
{
	game->ray_angle	-=	2;
	game->ray_angle	=	FixAng(game->ray_angle);
	game->delta_x	=	cos(deg2rad(game->ray_angle));
	game->delta_y	=	-sin(deg2rad(game->ray_angle));
	// drawRays2D(game);
}

void	a_press(t_game *game)
{
	game->ray_angle += 2; 
	game->ray_angle = FixAng(game->ray_angle); 
	game->delta_x = cos(deg2rad(game->ray_angle));
	game->delta_y = -sin(deg2rad(game->ray_angle));
	// drawRays2D(game);
}
