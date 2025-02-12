/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:15:59 by malbayra          #+#    #+#             */
/*   Updated: 2025/02/12 18:55:40 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_extension(char *map_file)
{
	size_t	i;

	i = ft_strlen(map_file) - 4;
	if (ft_strncmp(&map_file[i], ".ber", 4) == 0)
		return (1);
	return (0);
}

void	check_bor(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->row)
		if (map->map[i][0] != '1' || map->map[i][map->column - 1] != '1')
			return (0);
	i = -1;
	while (++i < map->column)
		if (map->map[0][i] != '1' || map->map[map->row - 1][i] != '1')
			return (0);
	return (1);
}

int	check_str(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	check_ecp(t_game *game)
{
	if (game->map.exit == 0 || game->map.exit > 1)
		error_free_msg(game, "Error: Invalid number of exit");
	if (game->map.collectibles == 0 || game->map.collectibles < 1)
		error_free_msg(game, "Error: Invalid number of collectibles");
	if (game->map.player == 0 || game->map.player > 1)
		error_free_msg(game, "Error: Invalid number of player");
}

void	check_count_el(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.row)
	{
		j = -1;
		while (++j < game->map.column)
		{
			if (check_str("ECP01", game->map.map[i][j]) == 0)
				error_free_msg(game, "Error: Invalid element in the map");
			if (game->map.map[i][j] == 'E')
				game->map.exit++;
			else if (game->map.map[i][j] == 'C')
				game->map.collectibles++;
			else if (game->map.map[i][j] == 'P')
			{
				game->map.player++;
				game->map.player_position = (t_position){i, j};
			}
		}
	}
	check_ecp(game);
}
