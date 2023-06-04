/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:25:52 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/09 19:25:54 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../cub3d.h"

int	check_char_0(char **map, int x, int y);
int	check_wrong_char(char c);
int	check_border(char **map, int x, int y);

// This function allows to know if the map is closed.
void	check_map_closed(t_all_structs *all_structs, char **map)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (map[i] != NULL)
	{
		while (map[i][x] != '\0')
		{
			if (map[i][x] == '0' && check_char_0(map, i, x))
				error_map_not_closed(all_structs);
			x++;
		}
		x = 0;
		i++;
	}
}

// This function allows to know if the character is an authorized character.
int	check_wrong_char(char c)
{
	if (c != '\0' && c != ' ')
		return (0);
	return (1);
}

// This function allows to know if the index of the table is a border.
int	check_border(char **map, int x, int y)
{
	if (x == 0 || y == 0 || map[x + 1] == NULL || map[x + 1][y] == '\0')
		return (1);
	return (0);
}

// This function allows to check all the boxes around a 0 character.
int	check_char_0(char **map, int x, int y)
{
	if (check_border(map, x, y) == 1)
		return (1);
	if (check_wrong_char(map[x - 1][y]) == 1)
		return (1);
	if (check_wrong_char(map[x][y - 1]) == 1)
		return (1);
	if (check_wrong_char(map[x][y + 1]) == 1)
		return (1);
	if (check_wrong_char(map[x + 1][y]) == 1)
		return (1);
	return (0);
}

char	**replace_space(char **map)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (map[i] != NULL)
	{
		while (map[i][x] != '\0')
		{
			if (map[i][x] == ' ')
				map[i][x] = '1';
			x++;
		}
		x = 0;
		i++;
	}
	return (map);
}
