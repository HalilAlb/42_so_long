/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:54:53 by malbayra          #+#    #+#             */
/*   Updated: 2025/02/12 16:59:38 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int chech_shape(t_game *game)
{
    size_t i;
    size_t j;

    j = game->map.column;
    i = 0;
    while(game->map.map[i] != NULL)
    {
        if (j != ft_strlen(game->map.map[i]))
            return (0);
        i++;   
    }
    
}

int unioncheck(t_game *game)
{
    if(chech_shape(game) == 0)
        error_free_msg(game, "Error: Map is not rectangular");
    
}