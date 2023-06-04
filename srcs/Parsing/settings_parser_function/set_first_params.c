/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_first_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:02:54 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/12 18:02:55 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"../../cub3d.h"

int		is_newline(char *str);
char	**set_map(t_settings *set, char **file, int file_height, int cursor);
char	**set_new_map(t_settings *settings, char **map);;
void	error_no_map_in_file(t_settings *settings);
void	error_null_map(char **all_params);
char	**check_only_space(t_settings *settings, char **map);

// This function allows to set the first 6 lines of the file as parameters.
char	**set_first_params(t_settings *settings, char **file, int file_height)
{
	char	**params;
	int		i;
	int		x;

	i = 0;
	x = 0;
	params = malloc(sizeof(char *) * 7);
	if (!params)
		error_malloc(settings);
	while (file[i] != NULL && x < 6)
	{
		if (is_newline(file[i]))
			i++;
		else
		{
			params[x] = ft_strdup(file[i]);
			x++;
			i++;
		}
	}
	params[x] = NULL;
	settings->map = set_map(settings, file, file_height, i);
	if (settings->map == NULL)
		error_null_map(params);
	return (params);
}

// This function lets you know if the string is a newline.
int	is_newline(char *str)
{
	if (str == NULL)
		return (0);
	if (str[0] == '\n')
		return (1);
	return (0);
}

// This function allows you to set the map,
// in a double array stored in the settings structure.
char	**set_map(t_settings *set, char **file, int file_height, int cursor)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * file_height);
	if (!map)
		error_malloc(set);
	while (is_newline(file[cursor]))
		cursor++;
	if ((file_height - cursor) == 0)
	{
		free(map);
		error_no_map_in_file(set);
		return (NULL);
	}
	while (file[cursor] != NULL)
		map[i++] = ft_strdup(file[cursor++]);
	map[i] = NULL;
	if (check_only_space(set, map) == NULL)
		return (NULL);
	map = set_new_map(set, map);
	return (map);
}

void	error_null_map(char **all_params)
{
	free_2d_array(all_params);
	exit(EXIT_FAILURE);
}

char	**check_only_space(t_settings *settings, char **map)
{
	int			i;
	int			x;
	long long	find;

	i = 0;
	find = 0;
	while (map[i] != NULL)
	{
		x = 0;
		while (map[i][x] != '\0')
		{
			if (map[i][x] == '1' || map[i][x] == '0' || map[i][x] == 'N' \
				|| map[i][x] == 'S' || map[i][x] == 'W' || map[i][x] == 'E')
				find++;
			x++;
		}
		i++;
	}
	if (find == 0)
	{
		free_2d_array(map);
		error_no_map_in_file(settings);
		return (NULL);
	}
	return (map);
}
