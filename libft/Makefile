SRC =	ft_arrayadd.c			\
		ft_arraycpy.c			\
		ft_arrayfree.c			\
		ft_arrayintsrch.c		\
		ft_arraylen.c			\
		ft_arrayprint.c			\
		ft_arrayrm.c			\
		ft_arrayrm2.c			\
		ft_arraysrch.c			\
		ft_atoi.c				\
		ft_atol.c				\
		ft_bzero.c				\
		ft_calloc.c				\
		ft_charadd.c			\
		ft_is_str_alnum.c		\
		ft_isalnum.c			\
		ft_isalpha.c			\
		ft_isascii.c			\
		ft_isdigit.c			\
		ft_iseven.c				\
		ft_isprint.c			\
		ft_isquote.c			\
		ft_isuneven.c			\
		ft_iswhitespace.c		\
		ft_itoa.c				\
		ft_lstadd_back.c		\
		ft_lstadd_front.c		\
		ft_lstclear.c			\
		ft_lstdelone.c			\
		ft_lstiter.c			\
		ft_lstlast.c			\
		ft_lstmap.c				\
		ft_lstnew.c				\
		ft_lstsize.c			\
		ft_memchr.c				\
		ft_memcmp.c				\
		ft_memcpy.c				\
		ft_memmove.c			\
		ft_memset.c				\
		ft_pt_swap.c			\
		ft_putchar_fd.c			\
		ft_putendl_fd.c			\
		ft_putnbr_fd.c			\
		ft_putstr_fd.c			\
		ft_charrm.c				\
		ft_split.c				\
		ft_strchr.c				\
		ft_strcmp.c				\
		ft_strcpy.c				\
		ft_strdup.c				\
		ft_striteri.c			\
		ft_strjoin.c			\
		ft_strlcat.c			\
		ft_strlcpy.c			\
		ft_strlen.c				\
		ft_strmapi.c            \
		ft_strncmp.c            \
		ft_strnstr.c            \
		ft_strrchr.c			\
		ft_strtoupper.c			\
		ft_strtrim.c			\
		ft_substr.c				\
		ft_swap.c				\
		ft_tolower.c			\
		ft_toupper.c			\
		ft_free2d.c				\
		ft_strjoinf2.c			\
		ft_strendcmp.c			\

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER =-I  libft.h

### Repertoires ###
SRCS_DIR 	= srcs/
OBJS_DIR	= objs/
INCLUDE_DIR = include/

### Colour var ###
CURSOR_UP_1	= \033[1A
CURSOR_UP	= \033[2A#change 0 to change number of lignes
CURSOR_DOWN	= \033[1B

END			= \033[0m
BOLD		= \033[1m
ITALIC		= \033[3m
URL			= \033[4m
BLINK		= \033[5m
BLINK2		= \033[6m
SELECTED	= \033[7m

BLACK		= \033[30m
RED			= \033[31m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m
VIOLET		= \033[35m
CYAN		= \033[36m
WHITE		= \033[37m

OBJS = $(SRC:.c=.o)

SRC_IN_DIR = $(addprefix $(SRCS_DIR), $(SRC))
OBJS_IN_DIR = $(addprefix $(OBJS_DIR), $(OBJS))

###--------------------------## RULES ##--------------------------###
all: start

$(NAME) : $(OBJS_IN_DIR)
	@echo "$(CURSOR_UP)\033[2K$(GREEN)Compiling DONE! ✅$(END)$(CURSOR_DOWN)"
	@echo "$(BLUE)$(CURSOR_UP_1)Creating archive $(NAME)     $(END)"
	@ar -rc $(NAME) $^
	@echo "----------------------------"
	@echo "\n"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c 
	@mkdir -p $(OBJS_DIR)
	@echo "$(CURSOR_UP)\033[2KCompiling $@$(CURSOR_DOWN)"
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@


start:
ifeq ($(wildcard $(NAME)),)
	@echo "----------------------------"
	@echo "$(SELECTED)LIBFT$(END)"
	@echo " "
	@echo "----------------------------"
	@$(MAKE) $(NAME)
endif

re: fclean
	@$(MAKE) $(NAME)
	
clean:
	@rm -rf $(OBJS_DIR)
	@echo "LIBFT	|	$(CYAN)OBJECTS CLEANED$(END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(CURSOR_UP_1)LIBFT	|	$(BLUE)LIBRARY CLEANED$(END)"
re: fclean all
