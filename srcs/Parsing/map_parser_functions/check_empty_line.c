/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:38:48 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/09 19:38:51 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../cub3d.h"

int	is_empty_line(char *line_map);

// This function checks all the lines of the map to see if,
// there is an empty line.
void	check_empty_line(t_all_structs *all_structs, char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		if (is_empty_line(map[i]))
			error_map_empty_line(all_structs);
		i++;
	}
}

// This function is a boolean that allows to know,
// if the string is composed of just a line break.
int	is_empty_line(char *line_map)
{
	int	i;

	i = 0;
	while (line_map[i] != '\0')
	{
		if (line_map[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
