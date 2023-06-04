/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:22:11 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/07 21:22:12 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_non_existent_file(void)
{
	write(2, "Error\n", 6);
	write(2, "File don't exist.\n", 18);
	exit(EXIT_FAILURE);
}

void	error_empty_file(t_settings *settings, char **file)
{
	write(2, "Error\n", 6);
	write(2, "Empty file.\n", 12);
	free(settings->texture);
	free(file);
	exit(EXIT_FAILURE);
}

void	error_map_unknown_params(t_all_structs *all_structs, char c)
{
	write(2, "Error\nMap: '", 13);
	write(2, &c, 1);
	write(2, "' unknown parameter.\n", 22);
	free_error(&all_structs->settings);
	exit(EXIT_FAILURE);
}

void	error_empty_params(t_settings *settings, char **params)
{
	free_2d_array(params);
	free_error(settings);
	exit(EXIT_FAILURE);
}
