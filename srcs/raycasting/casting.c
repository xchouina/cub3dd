#include "../includes/cub3d.h"

void	draw_vertical_line(mlx_image_t *img, int r, int lineOff, int lineH, int color)
{
    int x = r * 10 + 540;
    int y1 = lineOff;
    int y2 = lineOff + lineH;
    // int i;
	// i = y1;
	printf("x=%d | y1=%d | y2=%d | lineH=%d\n", x, y1, y2, lineH);
	// int j;
	// int thickness = 5;
	// 	j = 0;
	// while (j++ < thickness)
		while (y1++ < y2)
		{
			mlx_put_pixel(img, x, y1, color);
			// printf("i=%d", i);
		}
}

void	draw_line(float x1, float y1, float x2, float y2, mlx_image_t *img)
{
    int player_width = 25;
    int player_height = 25;
    int player_center_x = x1 + (player_width / 2);
    int player_center_y = y1 + (player_height / 2);

    int dx = x2 - player_center_x;
    int dy = y2 - player_center_y;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xinc = (float) dx / (float) steps;
    float yinc = (float) dy / (float) steps;
    float x = player_center_x;
    float y = player_center_y;
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
	int	mapX = game->max_line + 2; //max value of x in the map
	int	mapY = game->map_height; //max value of Y in map
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

	px = game->sprite_player.img->instances[0].x;
	py = game->sprite_player.img->instances[0].y;

	ra = FixAng(game->ray_angle + 60);//ray set back 30 degrees
	
	i = 0;
	while (i++ < 120)
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
		int	wall_color = 0XFFFF00FF;
		if (disV < disH)
		{
			rx = vx;
			ry = vy;
			disH = disV;
			// wall_color = 0XFF00FF00;
		}//horizontal hit first
		// dprintf(2, "wall: %f | %f\nplayer: %d|%d\n", rx, ry, px, py);
		// draw_ray(px, py, game->ray_angle);

		// 320x160

		// map_creation(game);
		draw_line(px, py, rx, ry, game->mini_map_img);

		int ca = FixAng(game->ray_angle - ra);
		disH = disH * cos(deg2rad(ca)); //fix fisheye
		int lineH = (TILE_SIZE * 1980) / disH ; //200; //(mapS * 320) / (disH);
		if (lineH > 1980)
			lineH = 1980;//line height and limit
		int lineOff = 1080 - (lineH >> 1);//line offset
		draw_vertical_line(game->img, i, lineOff, lineH, wall_color);

		ra = FixAng(ra-1);//go to next ray
	}
}
