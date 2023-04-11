#ifndef RC_CUB3D_H
# define RC_CUB3D_H

# define WIN_W		1980
# define WIN_H		1080
# define TILE_SIZE	25
# define FOV		60		// Field of view
# define NUM_RAYS	2400	// Number of rays to cast
# define IM_SZ 		400
typedef struct s_rays //DATA FOR EACH RAYS
{
	float	angle; //degree
	float	x;		//check
	float	y;		//check
	float	wall[2];	//wall[0] = coord x || wall[1] = coord y
	float	h_check[2];
	float	v_check[2];
	float	dist;
	int		id;
	int		h_wall_found;
	int		v_wall_found;
}	t_rays;

// typedef struct s_line //FOR DRAW_LINE FUNCTION
// {
// 	int		player_center_x;
// 	int		player_center_y;
// 	int		dx;
// 	int		dy;
// 	int		steps;
// 	float	xinc;
// 	float	yinc;
// 	float	x;
// 	float	y;
// 	int		i;
// }t_line;

// typedef struct s_rc
// {
// 	// char	*map_str;
// 	int		mapX; 		//max value of x in the map
// 	int		mapY; 		//max value of Y in map
// 	int		i;
// 	int		mx; 		// map y value
// 	int		my; 		//map x value 
// 	int		mp; 		// position in array
// 	int		dof;		//depth of field
// 	int		side;
// 	float	vx;
// 	float	vy;
// 	float	rx; 		//gridline x
// 	float	ry; 		//gridline y
// 	float	ra; 		// ray
// 	float	xo; 		//offset x
// 	float	yo; 		//offset y
// 	float	disV;		//distance vertical
// 	float	disH; 		//distance horizontal
// 	float	Tan;		//negative tan
// 	int		px;			//player position x
// 	int		py;			//player position y
// 	int		wall_color;
// 	int 	ca;
// 	int 	lineH;
// 	int 	lineOff;

// }t_rc;





char *ft_double_2_singlearray(char **da);

int	rgb_to_int(int r, int g, int b);
# endif