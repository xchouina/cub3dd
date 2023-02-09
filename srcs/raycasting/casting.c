#include "../includes/cub3d.h"

void	init_raycast_assets(t_game *game)
{
	t_rc	*rc;

	rc = &game->rc;

	rc->init_angle = (2 * M_PI) / 3;
	rc->out_c_x = game->player.position_x;
	rc->out_c_y = game->player.position_y;
	rc->in_c_x = 12.5;
	rc->in_c_y = 12.5;
	rc->px_init_px = (rc->out_c_x)
	rc->px_init_py
	dprintf(1, "--> %f\n", rc->init_angle);
}

void	check_one(t_game *game) //distance from dot to first edge_of_cube
{
	t_rc	rc;
}

float	check_loop(t_game *game) //distance from first_cube to wall
{

	check_y - check_x;
	// if + --> 

}

void	dda_ray(t_game *game)
{
	check_one(t_game *game);
	check_loop(t_game *game);


}





// CONVERT DEGREE TO RADIANS
float	degrees_to_radians(float degrees) 
{
    return (degrees * M_PI) / 180.0;
}

// FIRST CHECK EN 'Y'
new_x = cur_x (+/-) (-dy / tanf(degrees_to_radians(angle)));
new_y = cur_y (+/-) dy;

if (game->map[new_y / 25][new_x / 25] == '1')
	dprintf(2, "THerE a WalL hErE\n");


// FIRST CHECK EN 'X'
new_x = cur_x (+/-) (25 - dx);
new_y = cur_y (+/-) ((25 - dx) * tanf(degrees_to_radians(angle)));

if (game->map[new_y / 25][new_x / 25] == '1')
	dprintf(2, "THerE a WalL hErE\n");