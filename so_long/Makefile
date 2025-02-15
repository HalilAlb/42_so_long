CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc
MLXFLAGS = -L ./minilibx-linux -lmlx -I./minilibx-linux -lXext -lX11
LIBFT = libft/libft.a
PRINTF = libft/ft_printf/libftprintf.a
GNL = libft/get_next_lilne/get_next_line.a
RM = rm -rf
NAME = so_long

SRCS = check_map.c \
    check_mapp.c \
    check_mappp.c \
    free.c \
    get_map.c \
    init_mlx.c \
    init_game.c \
    loop.c \
    player.c \
    render.c \
    utils.c \
    main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	# Libft'i, get_next_line ve ft_printf ile birlikte derle
	$(MAKE) -C libft/get_next_lilne
	$(MAKE) -C libft/ft_printf
	$(MAKE) -C libft
	$(MAKE) -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) $(PRINTF) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C libft/get_next_lilne
	$(MAKE) clean -C libft/ft_printf
	$(MAKE) clean -C libft
	$(RM) $(OBJS)

fclean: clean
	# get_next_line ve ft_printf'ı tamamen temizle
	$(MAKE) fclean -C libft/get_next_lilne
	$(MAKE) fclean -C libft/ft_printf
	$(MAKE) fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
