/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 07:32:52 by malbayra          #+#    #+#             */
/*   Updated: 2025/02/19 10:22:11 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit_game(t_game *game)
{
	error_free(game);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	on_press(int key, t_game *game)
{
	if (key == 65307)
		quit_game(game);
	else if (key == 119 || key == 65362)
		update_player_pos(game, false, -1);
	else if (key == 97 || key == 65361)
		update_player_pos(game, true, -1);
	else if (key == 115 || key == 65364)
		update_player_pos(game, false, 1);
	else if (key == 100 || key == 65363)
		update_player_pos(game, true, 1);
	return (EXIT_SUCCESS);
}

void	hook_n_run(t_game *game)
{
	mlx_hook(game->mlx_wind, 2, (1L << 0), on_press, game);
	mlx_hook(game->mlx_wind, 17, (1L << 17), quit_game, game);
	mlx_loop(game->mlx_init);
}
