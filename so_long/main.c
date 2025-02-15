/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:26:15 by malbayra          #+#    #+#             */
/*   Updated: 2025/02/15 11:10:41 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ac_check(int ac, char **av)
{
	if (ac != 2)
		error_free_msg(NULL, "Error: Invalid number of ac");
	if (*av[1] == '\0')
		error_free_msg(NULL, "Map is null");
}

int	main(int ac, char **av)
{
	t_game	game;

	ac_check(ac, av);
	game = init_game();
	get_map(av[1], &game);
	unioncheck(&game);
	init_mlx(&game);
	render_map(&game);
	hook_n_run(&game);
	return (EXIT_SUCCESS);
}
