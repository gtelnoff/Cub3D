/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_parsing_one.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 02:43:01 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/02/01 02:43:02 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_map_empty_line(t_all_structs *all_structs)
{
	free_error(&all_structs->settings);
	write(2, "Error\n", 7);
	write(2, "Map: empty line in map config.\n", 31);
	exit(EXIT_FAILURE);
}

void	error_map_not_closed(t_all_structs *all_structs)
{
	free_error(&all_structs->settings);
	write(2, "Error\n", 7);
	write(2, "Map: the map is not closed.\n", 29);
	exit(EXIT_FAILURE);
}

void	error_player_already_set(t_all_structs *all_structs)
{
	free_error(&all_structs->settings);
	write(2, "Error\n", 7);
	write(2, "Player: there is more than one player.\n", 40);
	exit(EXIT_FAILURE);
}

void	error_player_not_exist(t_all_structs *all_structs)
{
	free_error(&all_structs->settings);
	write(2, "Error\n", 7);
	write(2, "Player: the player doesn't exist.\n", 35);
	exit(EXIT_FAILURE);
}

void	error_no_map_in_file(t_settings *settings)
{
	free_error(settings);
	write(2, "Error\n", 7);
	write(2, "Map: no map in file\n", 20);
}
