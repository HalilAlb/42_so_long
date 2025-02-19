/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:11:59 by malbayra          #+#    #+#             */
/*   Updated: 2025/02/19 10:24:04 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_row(char *map_file, t_game *game)
{
	char	*temp;
	int		counter;
	int		temp_map_file;

	counter = 0;
	temp_map_file = open(map_file, O_RDONLY);
	if (temp_map_file == -1)
		error_free_msg(game, "ERROR Failed to open map file");
	temp = get_next_line(temp_map_file);
	while (temp)
	{
		counter += 1;
		free(temp);
		temp = get_next_line(temp_map_file);
	}
	if (counter == 0)
		error_free_msg(game, "Error Empty file");
	game->map.row = counter;
	close(temp_map_file);
}

void	read_row(char *map_file, t_game *game)
{
	int	i;
	int	temp_map_file;

	temp_map_file = open(map_file, O_RDONLY);
	if (temp_map_file == -1)
		error_free_msg(game, "Error Failed to open map file");
	i = 0;
	while (i < game->map.row)
		game->map.map[i++] = get_next_line(temp_map_file);
	game->map.map[i] = NULL;
	close(temp_map_file);
	i = 0;
	while (i < game->map.row)
	{
		game->map.map[i] = trim_free(game->map.map[i], "\n");
		if (!game->map.map[i])
			error_free_msg(game, "Malloc() err");
		i++;
	}
	game->map.column = ft_strlen_endl(game->map.map[0]);
}

void	get_map(char *file_map, t_game *game)
{
	if (check_file_extension(file_map) == 0)
		error_free_msg(game, "Error:invalid map file");
	get_row(file_map, game);
	game->map.map = malloc((game->map.row + 1) * sizeof(char *));
	if (!game->map.map)
		error_free_msg(game, "Malloc() error");
	read_row(file_map, game);
}
