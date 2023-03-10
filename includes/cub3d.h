#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <libft/include/libft.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "Get_next_line/get_next_line.h"
# include "rc_cub3d.h"

# define TILE_SIZE 25
# define FOV_ANGLE 60 * (M_PI / 180) // Field of view angle in radians
# define NUM_RAYS 120 // Number of rays to cast
# define PSPEED		2
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
	int	player_pos_y;
	int	player_pos_x;
	bool	enabled;
}	t_mlx_instance;

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
	char	NEWS;
}t_pos;

typedef struct s_player
{
	t_pos	player_mm;
} t_player;

typedef struct s_sprite
{
	xpm_t *xpm;
	mlx_image_t *img;

} t_sprite;

typedef struct s_game
{
	mlx_t	*mlx;
	void	*window;
	t_rc	*rc;
// ASSETS/TEXTURES
	t_player	player;
	t_sprite	sprite_player;
	t_sprite	wall;
	t_sprite	ground;
	xpm_t	*wall_mm;
	xpm_t	*ground_mm;
	char	**textures_tab;
// 
	t_mlx_instance *instance;
	int		width;
	int		height;
	mlx_image_t	*img;
	mlx_image_t	*mini_map_img;
	int		map_x;
	int		map_y;
	int		height_fd;
	int		fd;
	char	**map;
	char	**square_map;
	char	**tab_fd;
	int		map_start;
	int		map_height;
	int		max_line;
	int		checker;
	int		dir_NO;
	int		dir_SO;
	int		dir_WE;
	int		dir_EA;
	int		dir_F;
	int		dir_C;
	int		direction_complete;
	int		doublons;
	int		image;
	float	ray_angle;
	float	delta_x;
	float	delta_y;
	t_pos	pos;
	t_pos	first_red_pixel;
	t_textures	textures;
}t_game;

void	ft_quit(t_game *game);
void	fd_create_tab_fd(t_game *game, char *argv);
void	fill_tab_fd(t_game *game);
void	open_fd(char *argv, t_game *game);
int		parsing(t_game *game, char *argv);
void	fd_create_tab_map(t_game *game);
void	fill_tab_map(t_game *game);
void	incr_map_height(char *str, t_game *map);
void	fill_map_tab(t_game *game);
void	check_direction(t_game *game);
void	check_direction_2(t_game *game, int i);
void	check_direction_complete(t_game *game);
void	check_if_map_last(t_game *game, int i);
void	check_map(t_game *game);
void	check_symbol_and_doublon(t_game *game);
void	check_end_line(t_game *game, int i, int j);
void	init_value(t_game *game);
void	check_few_arg(t_game *game);
void	floodfill(int x, int y, t_game *game);
void	key_hook_move(void *param);

int		parsing_path(t_game *game);
void	get_text_path(t_game *game, int i, char *str_space, char *str_tab, int n);
void	get_floor_color(t_game *game, int i);
void	get_roof_color(t_game *game, int i);
void	init_texture_tab(t_game *game);
void	split_colors(t_game *game);
void	fd_null(t_game *game);
void	check_comma(t_game *game);
void	mlx_press_key(t_game *game);
uint8_t	get_img_color(mlx_image_t *img, int x, int y, t_game *game);
void	square_map(t_game *game);
void	fill_square_map(int i, int j, t_game *game);

// move_player
void	top_move(t_game *game);
void	down_move(t_game *game);
void	w_press(t_game *game);
void	s_press(t_game *game);
void	d_press(t_game *game);
void	a_press(t_game *game);

//print_test
void	print_player_pos(t_game *game);
void	print_tab_fd(t_game *map);
void	print_map(t_game *tab);
void	print_floodfill(t_game *game);



// ENGINE
int		starting_engine(t_game	*game);
void	map_creation(t_game *game);
void	init_raycast_assets(t_game *game);
void drawRays2D(t_game *game);
#endif
