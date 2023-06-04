/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_settings_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:46:51 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/10 19:46:54 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_settings_struct(t_settings *settings)
{
	free_2d_array(settings->file);
	free_2d_array(settings->map);
	free(settings->ceiling_color);
	free(settings->floor_color);
	free(settings->texture);
}

void	free_error(t_settings *settings)
{
	int	i;

	i = 0;
	free_2d_array(settings->file);
	free_2d_array(settings->map);
	free(settings->ceiling_color);
	free(settings->floor_color);
	while (i < 4)
	{
		if (settings->texture[i].addr_texture != NULL)
			free(settings->texture[i].addr_texture);
		i++;
	}
	free(settings->texture);
}

int	turn_off(t_all_structs *all_structs)
{
	mlx_destroy_image(all_structs->mlx.mlx, all_structs->mlx.image);
	ft_close(all_structs);
	return (0);
}

int	ft_close(t_all_structs *all_structs)
{
	int	i;

	i = 0;
	mlx_destroy_window(all_structs->mlx.mlx, all_structs->mlx.win);
	while (i < 4)
	{
		if (all_structs->settings.texture[i].image != NULL)
			mlx_destroy_image(all_structs->mlx.mlx, \
				all_structs->settings.texture[i].image);
		i++;
	}
	mlx_destroy_display(all_structs->mlx.mlx);
	free(all_structs->mlx.mlx);
	free_settings_struct(&all_structs->settings);
	exit(0);
	return (0);
}
