/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_horizontal_wall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 00:51:41 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/31 00:51:44 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../cub3d.h"

int	set_rays_casting_x_values(t_all_structs *all_structs, \
	double x, double y, double ro);
int	check_crossroads_x(t_all_structs *all_structs, int y, int x);

double	*hit_horizontal_wall(t_all_structs *all_structs, \
	double x, double y, double ro)
{
	int		step;
	double	*coordinate;

	coordinate = malloc(sizeof(double) * 2);
	step = set_rays_casting_x_values(all_structs, x, y, ro);
	while (step < all_structs->settings.length_map)
	{
		if (ro > PI / 2 && ro < ((3 * PI) / 2))
			step += check_crossroads_x(all_structs, (int)all_structs->cast.ry \
				/ 32, (int)all_structs->cast.rx / 32 - 1);
		else
			step += check_crossroads_x(all_structs, (int)all_structs->cast.ry \
				/ 32, (int)all_structs->cast.rx / 32);
	}
	coordinate[0] = all_structs->cast.rx;
	coordinate[1] = all_structs->cast.ry;
	return (coordinate);
}

int	set_rays_casting_x_values(t_all_structs *all_structs, \
	double x, double y, double ro)
{
	double	atan;

	atan = -tan(ro);
	if (ro > PI / 2 && ro < ((3 * PI) / 2))
	{
		all_structs->cast.rx = floor(x) * 32;
		all_structs->cast.ry = ((x * 32) - all_structs->cast.rx) \
			* atan + (y * 32);
		all_structs->cast.xo = -32;
		all_structs->cast.yo = -all_structs->cast.xo * atan;
	}
	if (ro < PI / 2 || ro > ((3 * PI) / 2))
	{
		all_structs->cast.rx = (ceil(x) * 32);
		all_structs->cast.ry = ((x * 32) - all_structs->cast.rx) \
			* atan + (y * 32);
		all_structs->cast.xo = 32;
		all_structs->cast.yo = -all_structs->cast.xo * atan;
	}
	if (ro == PI / 2 || ro == 3 * PI / 2)
	{
		imposible_angle(all_structs);
		return (all_structs->settings.length_map);
	}
	return (0);
}

int	check_crossroads_x(t_all_structs *all_structs, int y, int x)
{
	if (all_structs->cast.ry > 0 && all_structs->cast.rx > 0 \
		&& all_structs->cast.ry / 32 < all_structs->settings.heigth_map \
			&& all_structs->cast.rx / 32 <= all_structs->settings.length_map \
				&& all_structs->settings.map[y][x] == '1')
		return (all_structs->settings.length_map);
	else
	{
		all_structs->cast.rx += all_structs->cast.xo;
		all_structs->cast.ry += all_structs->cast.yo;
		return (1);
	}
}
