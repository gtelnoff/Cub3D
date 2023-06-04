/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:24:35 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/08 12:24:36 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../cub3d.h"

void	error_malloc(t_settings *settings)
{
	free_2d_array(settings->file);
	free_2d_array(settings->map);
	if (settings->ceiling_color != NULL)
		free(settings->ceiling_color);
	if (settings->floor_color != NULL)
		free(settings->floor_color);
	if (settings->texture != NULL)
		free(settings->texture);
	exit(EXIT_FAILURE);
}

void	error_unknown_params(t_settings *settings, char **params, char *name)
{
	write(2, "Error\n'", 7);
	ft_putstr_fd(name, 2);
	write(2, "': Unknown params.\n", 19);
	free_2d_array(params);
	free_error(settings);
	exit(EXIT_FAILURE);
}

void	write_to_space(char *params)
{
	int	i;

	i = 0;
	while (params[i] != ' ')
	{
		write(2, &params[i], 1);
		i++;
	}
}

void	error_settings_already_set(t_settings *settings, \
	char **all_params, char *params)
{
	write(2, "Error\n'", 7);
	write_to_space(params);
	write(2, "': Params already set.\n", 23);
	free_2d_array(all_params);
	free_error(settings);
	exit(EXIT_FAILURE);
}

void	error_colors_format(t_settings *settings, \
	char **all_params, char *params)
{
	write(2, "Error\n'", 7);
	write_to_space(params);
	write(2, "': Bad format.\n", 15);
	free_2d_array(all_params);
	free_error(settings);
	exit(EXIT_FAILURE);
}
