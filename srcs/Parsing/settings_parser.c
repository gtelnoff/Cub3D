/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_all_pramameters.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:15:10 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/08 14:15:11 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"../cub3d.h"

char	**set_first_params(t_settings *settings, char **file, int file_height);
void	check_no_empty_params(t_settings *settings, char **params);
void	check_duplicate_params(t_settings *settings, char **params);
void	check_have_unknow_params(t_settings *settings, char **params);
void	check_colors(t_settings *settings, char **params);
void	convert_rgb_to_hex(t_settings *settings);
void	check_extension(t_settings *settings);

void	settings_parser(t_all_structs *all_structs, char **file)
{
	char	**params;
	int		file_height;

	file_height = get_file_heigth(all_structs, all_structs->settings.map_name);
	check_extension(&all_structs->settings);
	params = set_first_params(&all_structs->settings, file, file_height);
	check_no_empty_params(&all_structs->settings, params);
	check_have_unknow_params(&all_structs->settings, params);
	check_duplicate_params(&all_structs->settings, params);
	params = trim_2d_array(params, "\n");
	check_colors(&all_structs->settings, params);
	free_2d_array(params);
	convert_rgb_to_hex(&all_structs->settings);
}
