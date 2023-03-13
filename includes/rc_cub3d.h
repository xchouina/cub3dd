#ifndef RC_CUB3D_H
# define RC_CUB3D_H

typedef struct s_rc
{
	int	mapX; //max value of x in the map
	int	mapY; //max value of Y in map
	int	i;
	int	mx; // map y value
	int	my; //map x value 
	int	mp; // map position of 
	int	dof; //depth of field
	int	side; 
	float	vx;
	float	vy;
	float	rx; //gridline x
	float	ry; //gridline y
	float	ra; // ray
	float	xo; //offset x
	float	yo; //offset y
	float	disV; //distance vertical
	float	disH; //distance horizontal
	float	Tan; //negative tan
	int		px; //player position x
	int		py; //player position y
	int	wall_color;
	int ca;
	int lineH;
	int lineOff;

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