/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 08:38:45 by malbayra          #+#    #+#             */
/*   Updated: 2025/02/15 08:39:24 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx_init = mlx_init();
	if (!game->mlx_init)
		error_free_msg(game, "Error : failed to initialize mlx");
	game->mlx_wind = mlx_new_window(game->mlx_init, game->map.column
			* BLOCK_SIZE, game->map.row * BLOCK_SIZE, "so_long");
	if (!game->mlx_wind)
		error_free_msg(game, "Error : Failed to open new window");
}