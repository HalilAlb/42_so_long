CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -lm -lXext -lX11
LIBFT = libft/libft.a
LIBFTDIR = libft
PRINTF = libft/ft_printf/libftprintf.a
PRINTFDIR = libft/ft_printf
GNLDIR = libft/get_next_lilne
GNL = libft/get_next_lilne/get_next_line.a
MLX = minilibx-linux/libmlx.a
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

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(GNL) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) $(PRINTF) $(MLX) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFTDIR) -I $(PRINTFDIR) -I $(GNLDIR) -I $(MLX) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR) > /dev/null 2>&1

$(PRINTF):
	@$(MAKE) -C $(PRINTFDIR) > /dev/null 2>&1

$(GNL): $(GNLDIR)
	@$(MAKE) -C $(GNLDIR) > /dev/null 2>&1

clean:
	$(MAKE) clean -C $(GNLDIR)
	$(MAKE) clean -C $(PRINTFDIR)
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(GNLDIR)
	$(MAKE) fclean -C $(PRINTFDIR)
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re

