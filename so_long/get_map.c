/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:11:59 by malbayra          #+#    #+#             */
/*   Updated: 2025/02/12 16:14:27 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(char *file_map, t_game *game)
{
	if (check_file_extension(file_map) == 0)
		error_free_msg(game, "Error:invalid map file");
}