/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ceil_floor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 00:01:57 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/31 00:02:06 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../cub3d.h"

void	print_ceil_floor(t_all_structs *all_structs)
{
	int	cloud_color;
	int	floor_color;
	int	x;
	int	y;

	cloud_color = all_structs->settings.ceiling_color[0];
	floor_color = all_structs->settings.floor_color[0];
	x = 0;
	y = 0;
	while (y <= WIN_SIZE_Y)
	{
		x = 0;
		while (x <= WIN_SIZE_X)
		{
			if (y <= WIN_SIZE_Y / 2)
				my_mlx_pixel_put(&all_structs->mlx, x, y, cloud_color);
			else
				my_mlx_pixel_put(&all_structs->mlx, x, y, floor_color);
			x++;
		}
		y++;
	}
}
