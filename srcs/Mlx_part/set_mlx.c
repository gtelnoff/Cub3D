/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:04:08 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/16 16:04:10 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../cub3d.h"

void	set_all_texture(t_all_structs *all_structs);
char	*set_texture(t_all_structs *all_structs, char *texture_name, int nbr);
void	free_addr_texture(t_settings *settings, int nbr);

void	set_mlx(t_all_structs *all_structs)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
	{
		free(all_structs->settings.texture[0].addr_texture);
		free(all_structs->settings.texture[1].addr_texture);
		free(all_structs->settings.texture[2].addr_texture);
		free(all_structs->settings.texture[3].addr_texture);
		free_settings_struct(&all_structs->settings);
		write(2, "Error\nMlx problem.\n", 20);
		exit(0);
	}
	mlx.win = mlx_new_window(mlx.mlx, WIN_SIZE_X, WIN_SIZE_Y, "Cub3d");
	all_structs->mlx = mlx;
	set_all_texture(all_structs);
}

void	set_all_texture(t_all_structs *all_structs)
{
	all_structs->settings.texture[0].addr_texture = \
		set_texture(all_structs, \
			all_structs->settings.texture[0].addr_texture, 0);
	all_structs->settings.texture[1].addr_texture = \
		set_texture(all_structs, \
			all_structs->settings.texture[1].addr_texture, 1);
	all_structs->settings.texture[2].addr_texture = \
		set_texture(all_structs, \
			all_structs->settings.texture[2].addr_texture, 2);
	all_structs->settings.texture[3].addr_texture = \
		set_texture(all_structs, \
			all_structs->settings.texture[3].addr_texture, 3);
}

char	*set_texture(t_all_structs *all_structs, char *texture_name, int nbr)
{
	texture_name = ft_strtrim_free(texture_name, "\n");
	all_structs->settings.texture[nbr].image = \
		mlx_xpm_file_to_image(all_structs->mlx.mlx, texture_name, \
			&all_structs->settings.texture[nbr].width, \
				&all_structs->settings.texture[nbr].heigth);
	if (all_structs->settings.texture[nbr].image == NULL)
	{
		write(2, "Error\n", 6);
		write(2, "Bad texture or not .xpm\n", 25);
		free_addr_texture(&all_structs->settings, nbr);
		free(texture_name);
		ft_close(all_structs);
	}
	free(texture_name);
	texture_name = \
		mlx_get_data_addr(all_structs->settings.texture[nbr].image, \
			&all_structs->settings.texture[nbr].bits_per_pixel, \
				&all_structs->settings.texture[nbr].line_length, \
					&all_structs->settings.texture[nbr].endian);
	return (texture_name);
}

void	free_addr_texture(t_settings *settings, int nbr)
{
	nbr++;
	while (nbr < 4)
	{
		free(settings->texture[nbr].addr_texture);
		nbr++;
	}
}
