###_*_*_*_*_*_*_*_*_*_*_*_*_Makefile_cub3d_*_*_*_*_*_*_*_*_*_*_*_*_###
###-------------------------# VARIABLES ##-------------------------###

CFILES =	cub3d.c 					\
			quit.c 						\
			parsing.c					\
			parsing_2.c					\
			create_tab.c				\
			check_map.c					\
			raycasting/engine.c			\
			raycasting/minimap.c		\
			raycasting/casting.c 		\
			raycasting/toolbox.c		\
			init_values.c				\
			get_texture_path_1.c 		\
			get_texture_path_2.c 		\
			key_hook.c					\
			move_mini_player.c			\

NAME = cub3d

SRCS = $(addprefix srcs/, $(CFILES))

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -g -Werror -Wextra -Wall -Iincludes -I.

LIBS =	libft/libft.a		\

GET_NEXT_LINE = get_next_line.c get_next_line_utils.c 
GNL_HEADER = ./Get_next_line/get_next_line.h
GNL_PATH = ./Get_next_line/
GNL_SRCS = $(addprefix $(GNL_PATH), $(GET_NEXT_LINE))
GNL_OBJS = ${GNL_SRCS:.c=.o}
MLX                = MLX42/libmlx42.a 
MLX_FLAG        = -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib

all: $(NAME)

.c.o :
	@$(CC) $(CFLAGS) -I$(GNL_HEADER) -c $< -o $@

$(NAME): $(OBJS) $(GNL_OBJS)
	@$(MAKE) -C libft
	@$(MAKE) -C MLX42
	@ $(CC) $(CFLAGS) $(GNL_OBJS) $(OBJS) $(LIBS) ${MLX} ${MLX_FLAG} -framework OpenGL -framework AppKit -o $(NAME)
	@echo "CUB3D	|	STATUS: \033[0;32mOK\033[0;00m"
	@echo "---------------------------------------------"

clean:
	@$(MAKE) -C libft clean
	@rm -rf $(OBJS) $(GNL_OBJS)
	@echo "CUB3D	|	STATUS: \033[0;36mCLEANED\033[0;00m"
	@echo "---------------------------------------------"
fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f $(NAME)

flcean: fclean
re: fclean all
