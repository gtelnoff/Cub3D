/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:37:20 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/09 19:37:21 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../cub3d.h"

int	is_parameters(char c);

// This function allows to check if all the parameters of the map are good.
void	check_all_params(t_all_structs *all_structs, char **map)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (map[i] != NULL)
	{
		while (map[i][x] != '\0')
		{
			if (!is_parameters(map[i][x]))
				error_map_unknown_params(all_structs, map[i][x]);
			x++;
		}
		x = 0;
		i++;
	}
}

// This function is a boole which allows to know if it is a map character.
int	is_parameters(char c)
{
	if (c != ' ' && c != '0' && c != '1' && c != 'N' \
		&& c != 'S' && c != 'E' && c != 'W' && c != '\n')
		return (0);
	return (1);
}
