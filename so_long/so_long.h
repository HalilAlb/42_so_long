/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:26:28 by malbayra          #+#    #+#             */
/*   Updated: 2025/02/12 18:33:39 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_lilne/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# include <stdlib.h>
# define WALL_BLOCK "./textures/wall.xpm"
# define FLOOR_BLOCK "./textures/flor.xpm"
# define PLAYER_BLOCK "./tesxtures/arwen.xpm"
# define COLLECTIBLES_BLOCK "./textures/rings.xpm"
# define EXIT_BLOCK "./textrues/door.xpm"
# define BLOCK_SIZE 64

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_block
{
	void		*exit;
	void		*collectibles;
	void		*player;
	void		*wall;
	void		*floor;
}				t_block;

typedef struct s_map
{
	char		**map;
	int			row;
	int			column;
	int			collectibles;
	int			player;
	int			exit;
	t_position	player_position;
}				t_map;

typedef struct s_game
{
	void		*mlx_init;
	void		*mlx_wind;
	int			moves;
	t_block		block;
	t_map		map;
}				t_game;

void			error_free_msg(t_game *game, char *error_msg);
t_game			init_game(void);
int				check_file_extension(char *map_file);
int				unioncheck(t_game *game);

#endif