/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array_with_all_params.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:19:32 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/08 12:19:34 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"../cub3d.h"

int	get_file_heigth(t_all_structs *all_structs, char *file_name);
int	check_file_exist(t_all_structs *all_structs, char *file_name);

// Allows to retrieve all the content of a file,
// and review it in a double table.
void	convert_file_to_2d_array(t_all_structs *all_structs, \
	char *file_name, int file_heigth)
{
	char	**all_map_settings;
	char	*line;
	int		fd;
	int		i;

	i = 1;
	all_map_settings = malloc(sizeof(char *) * (file_heigth + 1));
	if (!all_map_settings)
		error_malloc(&all_structs->settings);
	fd = check_file_exist(all_structs, file_name);
	line = get_next_line(fd);
	if (line == NULL)
		error_empty_file(&all_structs->settings, all_map_settings);
	all_map_settings[0] = line;
	while (line != NULL)
	{
		line = get_next_line(fd);
		all_map_settings[i] = line;
		i++;
	}
	close(fd);
	all_structs->settings.file = all_map_settings;
}

// Allows to know the number of lines of a file and to return it.
int	get_file_heigth(t_all_structs *all_structs, char *file_name)
{
	char	*line;
	int		fd;
	int		i;

	fd = check_file_exist(all_structs, file_name);
	line = get_next_line(fd);
	i = 0;
	if (line == NULL)
		return (0);
	while (line != NULL)
	{
		if (i == 0)
			free(line);
		line = get_next_line(fd);
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

// Allows to know if the file is existing or not.
int	check_file_exist(t_all_structs *all_structs, char *file_name)
{
	int	fd;

	fd = open(file_name, 0);
	if (fd == -1)
	{
		free(all_structs->settings.texture);
		error_non_existent_file();
	}
	return (fd);
}
