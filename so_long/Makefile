CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc
MLXFLAGS = -L ./mlx -lmlx -Ilmlx -lXext -lX11
LIBFT = ./libft/libft.a
RM = rm -rf
NAME = so_long

# Source files
SRCS = 
	check_map1.c \
	check_map2.c \
	check_path.c \
	free.c \
	get_map.c \
	init_game.c \
	init_mlx.c \
	loop.c \
	player.c \
	render_map.c \
	trim.c\
	main.c

# Object files
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./mlx
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

run: all clean

.SILENT: