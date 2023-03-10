#ifndef RC_CUB3D_H
# define RC_CUB3D_H

typedef struct s_rc
{
	// float	out_c_x; 		//distance en cubes 
	// float	out_c_y;
	// float	in_c_x; 		//distance en pixel, intra cube.
	// float	px_init_px; 	//nbr de pixels pour calculer la position en 'x'.
	// float	px_init_py;
	// float	in_c_y;
	// float	angle;
	// float	tan_theta;


	// ------------------------------- 
	// float	ray_angle;
	float	distance_to_wall;
	float	x_intercept;
	float	y_intercept;
	float	slope;
	int 	x_step;
	int		y_step;
	int		wall_hit_x;
	int		wall_hit_y;
	int		was_hit_vertical;
	int		pox; //player position
	int		poy;


}t_rc;

// MATHEMATIC VALUES ----------------
# define	RE			(M_PI * 2)			// RADIAN EAST	0 or 360
# define	RN			(M_PI / 2) 			// RADIAN NORTH	90
# define	RW			M_PI				// RADIAN WEST	180
# define 	RS			((3 * M_PI) / 2)	// RADIAN SOUTH	270
// ----------------------------------




// TOOLBOX.C
float	deg2rad(float degrees);
int		FixAng(int a);

# endif