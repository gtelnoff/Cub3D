/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_new_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:10:08 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/31 01:10:09 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../cub3d.h"

void	start_ray_casting(t_all_structs *all_structs, double i);

void	make_new_image(t_all_structs *all_structs)
{
	all_structs->mlx.addr = mlx_get_data_addr(all_structs->mlx.image, \
			&all_structs->mlx.bits_per_pixel, &all_structs->mlx.line_length, \
			&all_structs->mlx.endian);
	print_ceil_floor(all_structs);
	start_ray_casting(all_structs, -0.6);
	mlx_put_image_to_window(all_structs->mlx.mlx, all_structs->mlx.win, \
			all_structs->mlx.image, 0, 0);
}
