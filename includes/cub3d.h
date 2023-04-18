#ifndef CUB3D_H
# define CUB3D_H

# define WIN_W		1980
# define WIN_H		1080
# define TILE_SIZE	25
# define FOV		60		// Field of view
# define NUM_RAYS	2400	// Number of rays to cast

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <libft/include/libft.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "Get_next_line/get_next_line.h"

typedef enum keypress
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}	t_keypress;

typedef struct s_mlx_instance
{
	int32_t	x;
	int32_t	y;
	int		player_pos_y;
	int		player_pos_x;
	bool	enabled;
}t_mlx_instance;

typedef struct s_textures
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		couleur_floor;
	int		couleur_sky;

}t_textures;

typedef struct s_pos
{
	float	position_x;
	float	position_y;
	float	x;
	float	y;
}t_pos;

typedef struct s_player
{
	t_pos		player_mm;
	int			x;
	int			y;
	float		cx;
	float		cy;
	float		dx;
	float		dy;
	char		carddir;
	float		degrees;
}	t_player;

typedef struct s_sprite
{
	xpm_t		*xpm;
	mlx_image_t	*img;

}	t_sprite;

typedef struct s_text
{
	xpm_t		*xpm;
	uint32_t	**colors;
	char		*textures_path;
}	t_text;

typedef struct s_rays
{
	float	angle;
	float	x;
	float	y;
	float	wall[2];
	float	h_check[2];
	float	v_check[2];
	float	dist;
	int		id;
	int		h_wall_found;
	int		v_wall_found;
}	t_rays;

typedef struct s_game
{
	mlx_t			*mlx;
	void			*window;
	t_player		player;
	xpm_t			*wall_mm;
	xpm_t			*ground_mm;
	t_text			text[4];
	t_mlx_instance	*instance;
	int				width;
	int				height;
	mlx_image_t		*img;
	mlx_image_t		*mini_map_img;
	char			*ground_colors;
	char			*ceiling_colors;
	int				map_x;
	int				map_y;
	int				height_fd;
	int				fd;
	char			**map;
	char			*map_str;
	char			**square_map;
	char			**tab_fd;
	int				map_start;
	int				map_height;
	int				max_line;
	int				checker;
	t_rays			*rays;
	float			top_pixel;
	float			bot_pixel;
	float			tex_step;
	int				checking;
	int				dir_no;
	int				dir_so;
	int				dir_ea;
	int				dir_we;
	int				dir_f;
	int				dir_c;
	int				direction_complete;
	int				doublons;
	int				image;
	int				a_is_press;
	int				d_is_press;
	int				first_q_of_line;
	int				height_q;
	int				check_last_q;
	int				check_first_q;
	float			ray_angle;
	float			delta_x;
	float			delta_y;
	float			ang_incr;
	int				shader;
	t_pos			pos;
	t_pos			first_red_pixel;
	t_textures		textures;
}t_game;

int			rgbtab_to_int(char **rgb);
uint32_t	rgba_to_int(int r, int g, int b, int a);
void		ft_quit(t_game *game);
void		fd_create_tab_fd(t_game *game, char *argv);
void		fill_tab_fd(t_game *game);
void		open_fd(char *argv, t_game *game);
int			parsing(t_game *game, char *argv);
void		fd_create_tab_map(t_game *game);
void		fill_tab_map(t_game *game);
void		incr_map_height(char *str, t_game *map);
void		fill_map_tab(t_game *game);
void		check_direction(t_game *game);
void		check_direction_2(t_game *game, int i);
void		check_direction_complete(t_game *game);
void		check_if_map_last(t_game *game, int i);
void		check_map(t_game *game);
void		max_map(t_game *game);
void		check_symbol_and_doublon(t_game *game);
void		check_end_line(t_game *game, int i, int j);
void		init_value(t_game *game);
void		check_few_arg(t_game *game);
void		floodfill(int x, int y, t_game *game);
void		key_hook_move(void *param);
void		parsing_textures(t_game *game);
void		parsing_colors_we(t_game *game);
void		parsing_colors_no(t_game *game);
void		parsing_colors_ea(t_game *game);
void		parsing_colors_so(t_game *game);
void		print_colors_tab(t_game *game, int i);
void		print_colors_mlx42(t_game *game, int i);

int			parsing_path(t_game *game);
void		get_text_p(t_game *game, int i, char *str_space, char *str_tab);
void		get_floor_color(t_game *game, int i);
void		get_roof_color(t_game *game, int i);
void		init_texture_tab(t_game *game);
void		split_colors(t_game *game);
void		fd_null(t_game *game);
void		check_comma(t_game *game);
void		mlx_press_key(t_game *game);
uint8_t		get_img_color(mlx_image_t *img, int x, int y, t_game *game);
void		square_map(t_game *game);

void		sky_n_ground(t_game *game);
void		print_minimap(t_game *game);

// move_player
void		top_move(t_game *game);
void		down_move(t_game *game);
void		w_press(t_game *game);
void		s_press(t_game *game);
void		d_press(t_game *game);
void		a_press(t_game *game);

//print_test
void		print_player_pos(t_game *game);
void		print_tab_fd(t_game *map);
void		print_map(t_game *tab);
void		print_floodfill(t_game *game);

// TOOLBOX.C
float		deg2rad(float degrees);
int			fixang(int a);
void		fix_fisheye(t_game *game, t_rays *ray);

// ENGINE
int			starting_engine(t_game	*game);
void		map_creation(t_game *game);
void		init_raycast_assets(t_game *game);
void		init_player_data(t_game *game);
void		render(t_game *game);
void		drawRays2D(t_game *game);
void		print_wall(t_game *game, t_rays *ray, int x, int texture_index);
void		cast_rays(t_game *game);
void		render(t_game *game);
char		*ft_double_2_singlearray(char **da);
int			rgb_to_int(int r, int g, int b);

// CHECKS.C
int			check(t_game *game, t_rays *ray, float x, float y);
int			check_l(t_game *game, t_rays *ray, float x, float y);
void		loop_check_h(t_game *game, t_rays *ray, float theta);
void		loop_check_v(t_game *game, t_rays *ray, float theta);

//  CHECKS_2.C
void		first_check_h(t_game *game, t_rays *ray, float theta);
void		first_check_v(t_game *game, t_rays *ray, float theta);
void		check_horizontal(t_game *game, t_rays *ray);
void		check_vertical(t_game *game, t_rays *ray);

// PRINTING_WALLS.C
int			horiz_wall(t_game *game, t_rays *ray);
void		fix_fisheye(t_game *game, t_rays *ray);
int 		get_color(t_text *text, int y, int x);
void		draw_wall_texture(t_game *game, int x, int i, float texture_offset);
// void    draw_wall_texture(t_game *game, int x, float y_start, float y_end, int i, float texture_offset, float tex_step);
void    	print_wall(t_game *game, t_rays *ray, int x, int i);

// CASTING.C
void		create_rays(t_game *game);
void		fix_sign(t_rays *ray);
int			ret_zero(t_rays *ray);
void		cast_rays(t_game *game);

#endif
