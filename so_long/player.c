/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 07:56:53 by malbayra          #+#    #+#             */
/*   Updated: 2025/02/19 13:35:29 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player_block(t_game *game)
{
	char	*moves_str;

	game->moves += 1;
	mlx_put_image_to_window(game->mlx_init, game->mlx_wind, game->block.player,
		BLOCK_SIZE * game->map.player_position.x, BLOCK_SIZE
		* game->map.player_position.y);
	ft_printf("Move number: %d\n", game->moves);
}

void	which_block(t_game *game)
{
	if (game->map.map[game->map.player_position.y]
		[game->map.player_position.x] == 'C')
	{
		game->map.map[game->map.player_position.y]
		[game->map.player_position.x] = '0';
		game->map.collectibles -= 1;
		return ;
	}
	if (game->map.map[game->map.player_position.y]
		[game->map.player_position.x] == 'E'
		&& game->map.collectibles == 0)
	{
		ft_printf("You won\n");
		quit_game(game);
	}
}

void	update_left_behind_block(t_game *game)
{
	if (game->map.map[game->map.player_position.y]
		[game->map.player_position.x] == 'E')
	{
		mlx_put_image_to_window(game->mlx_init, game->mlx_wind,
			game->block.exit, BLOCK_SIZE * game->map.player_position.x,
			BLOCK_SIZE * game->map.player_position.y);
	}
	else
		mlx_put_image_to_window(game->mlx_init, game->mlx_wind,
			game->block.floor, BLOCK_SIZE * game->map.player_position.x,
			BLOCK_SIZE * game->map.player_position.y);
}

void	update_player_pos(t_game *game, bool horizontal, int length)
{
	if (horizontal)
	{
		if (game->map.map[game->map.player_position.y]
			[game->map.player_position.x + length] == '1')
			return ;
		update_left_behind_block(game);
		game->map.player_position.x += length;
	}
	else
	{
		if (game->map.map[game->map.player_position.y
				+ length][game->map.player_position.x] == '1')
			return ;
		update_left_behind_block(game);
		game->map.player_position.y += length;
	}
	which_block(game);
	put_player_block(game);
}
