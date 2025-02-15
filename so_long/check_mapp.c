/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:54:53 by malbayra          #+#    #+#             */
/*   Updated: 2025/02/15 11:09:38 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rect(t_game *game)
{
	size_t	i;
	size_t	j;

	j = game->map.column;
	i = 0;
	while (game->map.map[i] != NULL)
	{
		if (j != ft_strlen_endl(game->map.map[i]))
			return (0);
		i++;
	}
	return (1);
}

void	unioncheck(t_game *game)
{
	if (check_rect(game) == 0)
		error_free_msg(game, "Error: Map is not rectangular");
	check_count_el(game);
	if (check_bor(&game->map) == 0)
		error_free_msg(game, "Error : Invalid map borders");
	check_path(game);
}