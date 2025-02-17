/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:31:11 by malbayra          #+#    #+#             */
/*   Updated: 2025/02/17 08:31:43 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	init_game(void)
{
	return ((t_game){
		.map.map = NULL,
		.map.row = 0,
		.map.column = 0,
		.map.collectibles = 0,
		.map.exit = 0,
		.map.player = 0,
		.block.collectibles = NULL,
		.block.exit = NULL,
		.block.floor = NULL,
		.block.player = NULL,
		.block.wall = NULL,
		.moves = -1,
	});
}
