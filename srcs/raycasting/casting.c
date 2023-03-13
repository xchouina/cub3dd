#include "../includes/cub3d.h"

void	draw_vertical_line(mlx_image_t *img, int r, int lineOff, int lineH, int color)
{
    int x = r * 10 + 540;
    int y1 = lineOff;
    int y2 = lineOff + lineH;
    // int i;
	// i = y1;
	// printf("x=%d | y1=%d | y2=%d | lineH=%d\n", x, y1, y2, lineH);
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
    int player_center_x = x1 + (25 / 2);
    int player_center_y = y1 + (25 / 2);

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

void	init_raycast_values(t_game *game, t_rc *rc)
{
	rc->mapX = game->max_line + 2;
	rc->mapY = game->map_height;
	rc->px = game->sprite_player.img->instances[0].x;
	rc->py = game->sprite_player.img->instances[0].y;

}

void drawRays2D(t_game *game)
{
	t_rc *rc;

	rc = &game->rc;
	init_raycast_values(game, rc);
	rc->ra = FixAng(game->ray_angle + 60);//ray set back 30 degrees

	rc->i = 0;
	while (rc->i++ < 120)
	{
		//---Vertical--- 
		rc->dof = 0;
		rc->side = 0;
		rc->disV = 100000;
		rc->Tan = tan(deg2rad(rc->ra));
		if (cos(deg2rad(rc->ra)) > 0.001)
		{
			rc->rx = (((int)rc->px >> 6) << 6) + TILE_SIZE;
			rc->ry = (rc->px - rc->rx) * rc->Tan + rc->py;
			rc->xo = TILE_SIZE;
			rc->yo = -rc->xo * rc->Tan;
		}//looking left
		else if (cos(deg2rad(rc->ra)) < -0.001)
		{
			rc->rx = (((int)rc->px >> 6) << 6) - 0.0001;
			rc->ry = (rc->px - rc->rx) * rc->Tan + rc->py;
			rc->xo = -TILE_SIZE;
			rc->yo = -rc->xo * rc->Tan;
		}//looking right
		else 
		{
			rc->rx = rc->px;
			rc->ry = rc->py;
			rc->dof = 8;
		}//looking up or down. no hit  
		while (rc->dof < 8) 
		{
			rc->mx = (int)(rc->rx) >> 6;
			rc->my = (int)(rc->ry) >> 6;
			rc->mp = rc->my * rc->mapX + rc->mx;
			if (rc->mp > 0 && rc->mp < rc->mapX * rc->mapY && game->map[1][rc->mp] == '1')
			{
				rc->dof = 8;
				rc->disV = cos(deg2rad(rc->ra)) * (rc->rx - rc->px) - sin(deg2rad(rc->ra)) * ( rc->ry - rc->py);
			}//hit
			else
			{
				rc->rx += rc->xo;
				rc->ry += rc->yo;
				rc->dof += 1;
			}//check next horizontal
		}
		rc->vx = rc->rx;
		rc->vy = rc->ry;
		//---Horizontal---
		rc->dof = 0;
		rc->disH = 100000;
		rc->Tan = 1.0 / rc->Tan;
		if (sin(deg2rad(rc->ra)) > 0.001)
		{
			rc->ry = (((int)rc->py >> 6) << 6) - 0.0001;
			rc->rx = (rc->py - rc->ry) * rc->Tan + rc->px;
			rc->yo = -TILE_SIZE;
			rc->xo = -rc->yo * rc->Tan;
		}//looking up 
		else if (sin(deg2rad(rc->ra)) < -0.001)
		{
			rc->ry = (((int)rc->py >> 6) << 6) + TILE_SIZE;
			rc->rx = (rc->py - rc->ry) * rc->Tan + rc->px;
			rc->yo = TILE_SIZE;
			rc->xo = -rc->yo * rc->Tan;
		}//looking down
		else
		{
			rc->rx = rc->px;
			rc->ry = rc->py;
			rc->dof = 8;
		} //looking straight left or right
		while (rc->dof < 8)
		{
			rc->mx = (int)(rc->rx) >> 6;
			rc->my = (int)(rc->ry) >> 6;
			rc->mp = rc->my * rc->mapX + rc->mx;
			if (rc->mp > 0 && rc->mp < rc->mapX * rc->mapY && game->map[1][rc->mp] == '1')
			{
				rc->dof = 8;
				rc->disH = cos(deg2rad(rc->ra)) * (rc->rx - rc->px) -
					sin(deg2rad(rc->ra)) * (rc->ry - rc->py);
			}//hit
			else
			{
				rc->rx += rc->xo;
				rc->ry += rc->yo;
				rc->dof += 1;
			}//check next horizontal
		}
		rc->wall_color = 0XFFFF00FF;
		if (rc->disV < rc->disH)
		{
			rc->rx = rc->vx;
			rc->ry = rc->vy;
			rc->disH = rc->disV;
			// wall_color = 0XFF00FF00; //Different color for W/E or N/S
		}//horizontal hit first
		// dprintf(2, "wall: %f | %f\nplayer: %d|%d\n", rx, ry, px, py);
		// 320x160

		// map_creation(game);
		draw_line(rc->px, rc->py, rc->rx, rc->ry, game->mini_map_img);

		rc->ca = FixAng(game->ray_angle - rc->ra);
		rc->disH = rc->disH * cos(deg2rad(rc->ca)); //fix fisheye
		rc->lineH = (TILE_SIZE * 1980) / rc->disH ; //200; //(mapS * 320) / (disH);
		if (rc->lineH > 1980)
			rc->lineH = 1980;//line height and limit
		rc->lineOff = 1080 - (rc->lineH >> 1);//line offset
		draw_vertical_line(game->img, rc->i, rc->lineOff, rc->lineH,rc->wall_color);

		rc->ra = FixAng(rc->ra - 1);//go to next ray
	}
}
