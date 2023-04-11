#include "cub3d.h"

// black	= rgb_to_int(0, 0, 0)
// red		= rgb_to_int(255, 0, 0)
// green	= rgb_to_int(0, 255, 0);
// blue		= rgb_to_int(0, 0, 255);

int get_color(t_game *game, int i, int y, int x)
{
	int	res;

    dprintf(2, "%d, %d\n", y, x);
	if (game->shader == 1)
		res = ft_strjoin((char)game->textures[i].texture[y][x], 'FF');
	else
		res = ft_strjoin((char)game->textures[i].texture[y][x], '00');
   return(res);
}

void    print_wall(t_game *game, t_rays *ray, t_texture *texture, int i, mlx_image_t *img)
{
	float   wall_height;
	float   wall_width;
	float   y;
	float   x;
	int 	tx;
	int 	ty;
	int 	starter;
	int 	rat_x;
	int		rat_y;
	int 	rem_x;
	int 	h_cnt;
	int 	color;
	int 	rc;

	wall_height = (5 / ray->dist) * WIN_H;
	wall_width = (float)WIN_W / (float)NUM_RAYS;
	x = ray->id * wall_width;
	tx = (int)ray->wall[0] - ((int)ray->wall[0] / TILE_SIZE) * TILE_SIZE;
	ty = (int)ray->wall[1] - ((int)ray->wall[1] / TILE_SIZE) * TILE_SIZE;
	starter = ty;
	rat_x = TILE_SIZE / 25; //25 must be image dimensions
	rat_y = wall_height / 25;
	rem_x = 0;
	rc = 0;
	if (ty == 0)
	starter = tx;
	if (ray->dist <= 0.0001)
	ray->dist = 0.0001;
	if (wall_height > WIN_H)
	wall_height = WIN_H;
	if ((TILE_SIZE % 25) != 0)
	rem_x = TILE_SIZE / (TILE_SIZE % 25);
	while (x < wall_width * (ray->id + 1) && x <= (WIN_W + 1))
	{
		y = (WIN_W / 2) - (wall_height / 2);
		h_cnt = 0;
		while (y <= (WIN_W / 2) + (wall_height / 2) && h_cnt < wall_height)
		{
			// printing_texture(game, ray, i, wall_height, y, x);
			dprintf(2, "%f: %d , %d\n", wall_height,  h_cnt, starter);
			if (h_cnt > 24)
				h_cnt = 24;
			color = get_color(game, i, (h_cnt / rat_y), starter);
			mlx_put_pixel(img, x, y, color);
			h_cnt++;
			y++;
			while ((h_cnt) % rat_y != 0)
			{
				mlx_put_pixel(img, x, y, color);
				h_cnt++;
				y++;
			}
		}
		if (rem_x != 0 && rc % rem_x == 0)
		{
			dprintf(2, "%d , %d\n", h_cnt, starter);
			color = get_color(game, i, (h_cnt / rat_y), starter);
			mlx_put_pixel(img, ++x, y, color);
			h_cnt++;
			y++;
			while ((h_cnt) % rat_y != 0)
			{
				mlx_put_pixel(img, x, y, color);
				h_cnt++;
				y++;
			}
		}
		starter++;
		rc++;
		if (starter >= 25)
			starter = 0;
		x++;
	}
}




// game->text[0].colors[0][0], 
// printf("%d--%d--%d--%d--%d--%d--%d--%d--%d--%d--\n%d--%d--%d--%d--%d--%d--%d--%d--%d--%d--\n", 
// game->text[0].colors[0][0],
// game->text[0].colors[0][1],
// game->text[0].colors[0][2],
// game->text[0].colors[0][3],
// game->text[0].colors[0][4],
// game->text[0].colors[0][5],
// game->text[0].colors[0][6],
// game->text[0].colors[0][7],
// game->text[0].colors[0][8],
// game->text[0].colors[0][9],
// game->text[0].colors[1][0],
// game->text[0].colors[1][1],
// game->text[0].colors[1][2],
// game->text[0].colors[1][3],
// game->text[0].colors[1][4],
// game->text[0].colors[1][5],
// game->text[0].colors[1][6],
// game->text[0].colors[1][7],
// game->text[0].colors[1][8],
// game->text[0].colors[1][9],);