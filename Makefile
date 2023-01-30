###_*_*_*_*_*_*_*_*_*_*_*_*_Makefile_cub3d_*_*_*_*_*_*_*_*_*_*_*_*_###
###-------------------------# VARIABLES ##-------------------------###

CFILES =	cub3d.c 				\
			quit.c 					\
			parsing.c				\
			parsing_2.c				\
			create_tab.c			\
			check_map.c				\
			raycasting/engine.c		\
			raycasting/minimap.c	\
			init_values.c			\
			get_texture_path_1.c 	\
			get_texture_path_2.c 	\

SRCS = $(addprefix srcs/, $(CFILES))

NAME = cub3d

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -g -Werror -Wextra -Wall -Iincludes -I.

LIBS =	libft/libft.a		\

GET_NEXT_LINE = get_next_line.c get_next_line_utils.c 
GNL_HEADER = ./Get_next_line/get_next_line.h
GNL_PATH = ./Get_next_line/
GNL_SRCS = $(addprefix $(GNL_PATH), $(GET_NEXT_LINE))
GNL_OBJS = ${GNL_SRCS:.c=.o}
all: $(NAME)

.c.o :
	@$(CC) $(CFLAGS) -I$(GNL_HEADER) -c $< -o $@

$(NAME): $(OBJS) $(GNL_OBJS)
	@$(MAKE) -C libft
	@ $(CC) $(CFLAGS) $(GNL_OBJS) $(OBJS) $(LIBS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
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