#ifndef RC_CUB3D_H
# define RC_CUB3D_H

typedef struct s_rc
{
	float	out_c_x; 		//distance en cubes 
	float	out_c_y;
	float	in_c_x; 		//distance en pixel, intra cube.
	float	px_init_px; 	//nbr de pixels pour calculer la position en 'x'.
	float	px_init_py;
	float	in_c_y;
	float	angle;
	float	tan_theta;
}t_rc;

// MATHEMATIC VALUES ----------------

# define	RE			(M_PI * 2)			// 0 or 360
# define	RN			(M_PI / 2) 			// 90
# define	RW			M_PI				// 180
# define 	RS			((3 * M_PI) / 2)	// 270


// ----------------------------------

# endif