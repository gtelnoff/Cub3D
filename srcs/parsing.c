/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:21:02 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/07 17:21:04 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	define_settings_structs(t_settings *settings, char *file_name);
void	convert_file_to_2d_array(t_all_structs *all_structs, \
	char *file_name, int file_heigth);
void	settings_parser(t_all_structs *all_structs, char **file);
void	map_parser(t_all_structs *all_structs);
void	define_null_addr(t_settings *settings);

// This is the main function for parsing.
int	parsing(t_all_structs *all_structs, char *file_name)
{
	t_settings		settings;
	int				file_height;

	define_settings_structs(&settings, file_name);
	all_structs->settings = settings;
	file_height = get_file_heigth(all_structs, file_name);
	convert_file_to_2d_array(all_structs, file_name, file_height);
	settings_parser(all_structs, all_structs->settings.file);
	map_parser(all_structs);
	return (0);
}

void	define_settings_structs(t_settings *settings, char *file_name)
{
	settings->map = NULL;
	settings->map_name = file_name;
	settings->floor_color = NULL;
	settings->ceiling_color = NULL;
	settings->texture = malloc(sizeof(t_texture) * 4);
	if (!settings->texture)
		error_malloc(settings);
	define_null_addr(settings);
}
