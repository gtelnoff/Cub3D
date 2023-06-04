/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_vertical_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 00:51:57 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/31 00:51:58 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	set_rays_casting_y_values(t_all_structs *all_structs, \
	double x, double y, double ro);
int	check_crossroads_y(t_all_structs *all_structs, int y, int x);

double	*hit_vertical_wall(t_all_structs *all_structs, \
	double x, double y, double ro)
{
	int		step;
	double	*coordinate;

	coordinate = malloc(sizeof(double) * 2);
	step = set_rays_casting_y_values(all_structs, x, y, ro);
	while (step < all_structs->settings.heigth_map)
	{
		if (ro > PI)
			step += check_crossroads_y (all_structs, (int)all_structs->cast.ry \
				/ 32 - 1, (int)all_structs->cast.rx / 32);
		else
			step += check_crossroads_y (all_structs, (int)all_structs->cast.ry \
				/ 32, (int)all_structs->cast.rx / 32);
	}
	coordinate[0] = all_structs->cast.rx;
	coordinate[1] = all_structs->cast.ry;
	return (coordinate);
}

int	set_rays_casting_y_values(t_all_structs *all_structs, \
	double x, double y, double ro)
{
	double	atan;

	atan = -1 / tan(ro);
	if (ro > PI)
	{
		all_structs->cast.ry = floor(y) * 32;
		all_structs->cast.rx = ((y * 32) - all_structs->cast.ry) \
			* atan + (x * 32);
		all_structs->cast.yo = -32;
		all_structs->cast.xo = -all_structs->cast.yo * atan;
	}
	if (ro < PI)
	{
		all_structs->cast.ry = (ceil(y) * 32);
		all_structs->cast.rx = ((y * 32) - all_structs->cast.ry) \
			* atan + (x * 32);
		all_structs->cast.yo = 32;
		all_structs->cast.xo = -all_structs->cast.yo * atan;
	}
	if (ro == 0 || ro == PI)
	{
		imposible_angle(all_structs);
		return (all_structs->settings.heigth_map);
	}
	return (0);
}

int	check_crossroads_y(t_all_structs *all_structs, int y, int x)
{
	if (all_structs->cast.ry > 0 && all_structs->cast.rx > 0 \
		&& all_structs->cast.ry / 32 <= all_structs->settings.heigth_map \
			&& all_structs->cast.rx / 32 < all_structs->settings.length_map \
				&& all_structs->settings.map[y][x] == '1')
		return (all_structs->settings.heigth_map);
	else
	{
		all_structs->cast.rx += all_structs->cast.xo;
		all_structs->cast.ry += all_structs->cast.yo;
		return (1);
	}
}

void	imposible_angle(t_all_structs *all_structs)
{
	all_structs->cast.rx = 900;
	all_structs->cast.ry = 900;
}
