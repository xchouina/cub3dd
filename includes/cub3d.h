#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <libft/include/libft.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "Get_next_line/get_next_line.h"

typedef struct s_textures
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}t_textures;

typedef struct s_pos
{
	int	position_x;
	int	position_y;
	int	x;
	int	y;
	char	NEWS;
}t_pos;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		res_x;
	int		res_y;

// ASSETS/TEXTURES
	void	*player_mm;
	void	*wall_mm;
	void	*ground_mm;
// 

	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		map_x;
	int		map_y;
	// int		len;

	int		height_fd;
	char	**map;
	char	**tab_fd;
	int		map_start;
	int		map_height;
	int		checker;
	int		dir_NO;
	int		dir_SO;
	int		dir_WE;
	int		dir_EA;
	int		dir_F;
	int		dir_C;
	int		direction_complete;
	int		doublons;
	t_pos	player;
	t_textures	textures;
}t_game;

void	ft_quit(int fd);
void	fd_create_tab_fd(t_game *game, int fd, char *argv);
void	fill_tab_fd(t_game *game, int fd);
int		open_fd(char *argv);
int		parsing(t_game *game, int fd, char *argv);
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

//print_test
void	print_player_pos(t_game *game);
void	print_tab_fd(t_game *map);
void	print_map(t_game *tab);
void	print_floodfill(t_game *game);




// ENGINE
void	starting_engine(t_game	*game);
void	init_assets(t_game	*game);
void	map_creation(t_game *game);
#endif