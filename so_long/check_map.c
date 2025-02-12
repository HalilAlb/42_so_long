/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:15:59 by malbayra          #+#    #+#             */
/*   Updated: 2025/02/12 16:14:33 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_extension(char *map_file)
{
	size_t i;

	i = ft_strlen(map_file) - 4;
	if (ft_strncmp(&map_file[i], ".ber", 4) == 0)
		return (1);
	return (0);
}