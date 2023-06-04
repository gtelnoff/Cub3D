/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:16:21 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/09 14:16:23 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"../cub3d.h"

void	check_all_params(t_all_structs *all_structs, char **map);
void	check_empty_line(t_all_structs *all_structs, char **map);
void	check_map_closed(t_all_structs *all_structs, char **map);
void	equalize_map(t_all_structs *all_structs, char **map);
void	set_info_palyer(t_all_structs *all_structs, char **map);
char	**replace_space(char **map);

void	map_parser(t_all_structs *all_structs)
{
	check_all_params(all_structs, all_structs->settings.map);
	check_empty_line(all_structs, all_structs->settings.map);
	trim_2d_array(all_structs->settings.map, "\n");
	equalize_map(all_structs, all_structs->settings.map);
	check_map_closed(all_structs, all_structs->settings.map);
	set_info_palyer(all_structs, all_structs->settings.map);
	all_structs->settings.map = replace_space(all_structs->settings.map);
}
