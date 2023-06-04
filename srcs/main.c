/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:31:23 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/06 18:31:31 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int		parsing(t_all_structs *all_structs, char *file);
void	start_game(t_all_structs *all_structs);

void	error_to_many_argument(void)
{
	write(2, "Error\n", 7);
	write(2, "Usage: ./cub3d <file.cub>\n", 28);
	exit(EXIT_FAILURE);
}

//It's the main !
int	main(int ac, char **av)
{
	t_all_structs	all_structs;

	if (ac != 2)
		error_to_many_argument();
	parsing(&all_structs, av[1]);
	all_structs.player.x += 0.25;
	all_structs.player.y += 0.25;
	start_game(&all_structs);
	return (0);
}
