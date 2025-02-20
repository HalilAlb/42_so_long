/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:26:28 by malbayra          #+#    #+#             */
/*   Updated: 2025/02/20 14:42:05 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_lilne/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdbool.h>


# define WALL_BLOCK "textures/wall.xpm"
# define FLOOR_BLOCK "textures/floor.xpm"
# define PLAYER_BLOCK "textures/arwen.xpm"
# define COLLECTIBLES_BLOCK "textures/rings.xpm"
# define EXIT_BLOCK "textures/door.xpm"
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

void			ac_check(int ac, char **av);
int				check_file_extension(char *map_file);
int				check_bor(t_map *map);
int				check_str(char *str, int c);
void			check_ecp(t_game *game);
void			check_count_el(t_game *game);
int				check_rect(t_game *game);
void			unioncheck(t_game *game);
char			**copy_map(t_game *game);
int				flood_fill(t_map *map, t_position curr, char **temp_map);
void			check_path(t_game *game);
void			free_blocks(t_game *game);
void			init_mlx(t_game *game);
void			free_matrix(char **matrix);
void			error_free(t_game *game);
void			error_free_msg(t_game *game, char *error_msg);
void			get_row(char *map_file, t_game *game);
void			read_row(char *map_file, t_game *game);
void			get_map(char *file_map, t_game *game);
t_game			init_game(void);
int				quit_game(t_game *game);
int				on_press(int key, t_game *game);
void			hook_n_run(t_game *game);
void			put_player_block(t_game *game);
void			which_block(t_game *game);
void			update_left_behind_block(t_game *game);
void			update_player_pos(t_game *game, bool horizontal, int length);
void			render_map(t_game *game);
void			error_xpm(t_game *game);
void			xpm_to_image(t_game *game);
void			img_to_window(t_game *game);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*f_strchr(const char *str, int c);
char			*trim_free(char *s1, char const *set);
size_t			ft_strlen_endl(char *str);
void			reset_flood_fill(t_map *map, t_position start, char **temp_map,
					int *result);
#endif