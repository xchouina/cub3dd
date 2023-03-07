#include "../includes/cub3d.h"

void draw_line(float x1, float y1, float x2, float y2, mlx_image_t *img)
{
	int player_width = 50;
    int player_height = 50;
    int player_center_x = x1 - (player_width / 2);
    int player_center_y = y1 - (player_height / 2);

	x1 = player_center_x;
	y1 = player_center_y;
	int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xinc = (float) dx / (float) steps;
    float yinc = (float) dy / (float) steps;
    float x = x1;
    float y = y1;
    int i = 0;
    while (i++ <= steps)
    {
        if (x >= 0 && x < img->width && y >= 0 && y < img->height) 
            mlx_put_pixel(img, x, y, 0XFFFF00FF);
        x += xinc;
        y += yinc;
    }
}

void drawRays2D(t_game *game)
{
//  glColor3f(0,1,1); glBegin(GL_QUADS); glVertex2i(526,  0); glVertex2i(1006,  0); glVertex2i(1006,160); glVertex2i(526,160); glEnd();	
//  glColor3f(0,0,1); glBegin(GL_QUADS); glVertex2i(526,160); glVertex2i(1006,160); glVertex2i(1006,320); glVertex2i(526,320); glEnd();	 	
int	mapX = 50; //max value of x in the map
int	mapY = 50; //max value of Y in map
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
int		px;
int		py;

	px = game->sprite_player.img->instances[0].x;
	py = game->sprite_player.img->instances[0].y;

 ra = FixAng(game->ray_angle + 30);//ray set back 30 degrees
 
 i = 0;
 while (i++ < 6)
 {
	//---Vertical--- 
	dof = 0;
	side = 0;
	disV = 100000;
	Tan = tan(deg2rad(ra));
	if (cos(deg2rad(ra)) > 0.001)
	{
		rx = (((int)px >> 6) << 6) + TILE_SIZE;
		ry = (px - rx) * Tan + py;
		xo = TILE_SIZE;
		yo = -xo * Tan;
	}//looking left
	else if (cos(deg2rad(ra)) < -0.001)
	{
		rx = (((int)px >> 6) << 6) - 0.0001;
		ry = (px - rx) * Tan + py;
		xo = -TILE_SIZE;
		yo = -xo * Tan;
	}//looking right
	else 
	{
		rx = px;
		ry = py;
		dof = 8;
	}//looking up or down. no hit  
	while (dof < 8) 
	{
		mx = (int)(rx) >> 6;
		my = (int)(ry) >> 6;
		mp = my * mapX + mx;
		if (mp > 0 && mp < mapX * mapY && game->map[1][mp] == '1')
		{
			dof = 8;
			disV = cos(deg2rad(ra)) * (rx-px) - sin(deg2rad(ra)) * (ry-py);
		}//hit
		else
		{
			rx += xo;
			ry += yo;
			dof += 1;
		}//check next horizontal
	}
	vx = rx;
	vy = ry;
  //---Horizontal---
  	dof = 0;
  	disH = 100000;
 	Tan = 1.0 / Tan;
	if (sin(deg2rad(ra)) > 0.001)
	{
		ry = (((int)py >> 6) << 6) - 0.0001;
		rx = (py - ry) * Tan + px;
		yo = -TILE_SIZE;
		xo = -yo * Tan;
	}//looking up 
	else if (sin(deg2rad(ra)) < -0.001)
	{
		ry = (((int)py >> 6) << 6) + TILE_SIZE;
		rx = (py - ry) * Tan + px;
		yo = TILE_SIZE;
		xo = -yo * Tan;
	}//looking down
	else
	{
		rx = px;
		ry = py;
		dof = 8;
	} //looking straight left or right
	while (dof < 8)
	{
		mx = (int)(rx) >> 6;
		my = (int)(ry) >> 6;
		mp = my * mapX + mx;
		if (mp > 0 && mp < mapX * mapY && game->map[1][mp] == '1')
		{
			dof = 8;
			disH = cos(deg2rad(ra)) * (rx - px) - sin(deg2rad(ra)) * (ry - py);
		}//hit
		else
		{
			rx += xo;
			ry += yo;
			dof += 1;
		}//check next horizontal
	}
	// glColor3f(0,0.8,0);
	if (disV < disH)
	{
		rx = vx;
		ry = vy;
		disH = disV;
		// glColor3f(0,0.6,0);
	}//horizontal hit first
	dprintf(2, "wall: %f | %f\nplayer: %d|%d\n", rx, ry, px, py);
	// draw_ray(px, py, game->ray_angle);
	draw_line(px, py, rx, ry, game->mini_map_img);
	
	// glLineWidth(2);
	// glBegin(GL_LINES);
	// glVertex2i(px,py);
	// glVertex2i(rx,ry);
	// glEnd();//draw 2D ray
							// int ca = FixAng(game->ray_angle - ra);
							// disH = disH * cos(deg2rad(ca)); //fix fisheye
							// int lineH = 200; //(mapS * 320) / (disH);
							// if (lineH > 320)
							// 	lineH = 320;//line height and limit
	// int lineOff = 160 - (lineH>>1);//line offset
	// glLineWidth(8);
	// glBegin(GL_LINES);
	// glVertex2i(r*8+530,lineOff);
	// glVertex2i(r*8+530,lineOff+lineH);
	// glEnd();//draw vertical wall  
	ra = FixAng(ra-1);//go to next ray
	}
}
