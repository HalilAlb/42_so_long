CC = cc
CFLAGS =  -Iinc
MLXFLAGS = -L ./mlx -lmlx -Ilmlx -lXext -lX11
LIBFT = libft/libft.a
RM = rm -rf
NAME = so_long

SRCS = check_map.c \
	check_mapp.c \
	check_mappp.c \
	free.c \
	get_map.c \
	init_game.c \
	init_mlx.c \
	loop.c \
	player.c \
	render.c \
	utils.c \
	main.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	# Libft'i derle
	$(MAKE) -C libft/get_next_lilne
	$(MAKE) -C libft/ft_printf
	$(MAKE) -C libft
	# Minilibx'i derle
	$(MAKE) -C minilibx-linux
	# Projeyi derle
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C libft/get_next_lilne
	$(MAKE) clean -C libft/ft_printf
	$(MAKE) clean -C libft
	$(MAKE) clean -C minilibx-linux
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C libft/get_next_lilne
	$(MAKE) fclean -C libft/ft_printf
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C minilibx-linux
	$(RM) $(NAME)

re: fclean all
