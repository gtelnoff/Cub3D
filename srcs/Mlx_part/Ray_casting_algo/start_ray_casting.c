/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ray_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 00:57:20 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/31 00:57:21 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../cub3d.h"

double	*hit_horizontal_wall(t_all_structs *all_structs, double x, double y, \
	double ro);
double	*hit_vertical_wall(t_all_structs *all_structs, double x, double y, \
	double ro);
double	get_ray_length(t_all_structs *all_structs, double rx, double ry);
void	choose_west_or_east(t_all_structs *all_structs, double x, double y, \
	double angle);
void	choose_south_or_north(t_all_structs *all_structs, double x, double y, \
	double angle);
void	free_rx_ry(t_all_structs *all_structs, double *ray_x, double *ray_y);

void	start_ray_casting(t_all_structs *all_structs, double i)
{
	double	*ray_y;
	double	*ray_x;
	double	length_x;
	double	length_y;
	double	angle;

	angle = all_structs->player.angle - FOV;
	all_structs->player.count = 0;
	while (i < FOV)
	{
		angle = fix_pi(angle);
		ray_y = hit_vertical_wall(all_structs, all_structs->player.x, \
			all_structs->player.y, angle);
		ray_x = hit_horizontal_wall(all_structs, all_structs->player.x, \
			all_structs->player.y, angle);
		length_y = get_ray_length(all_structs, ray_y[0], ray_y[1]);
		length_x = get_ray_length(all_structs, ray_x[0], ray_x[1]);
		if (length_y > length_x)
			choose_south_or_north(all_structs, ray_x[0], ray_x[1], angle);
		else
			choose_west_or_east(all_structs, ray_y[0], ray_y[1], angle);
		i += 0.001;
		angle += 0.001;
		free_rx_ry(all_structs, ray_x, ray_y);
	}
}

double	get_ray_length(t_all_structs *all_structs, double rx, double ry)
{
	double	length;

	length = sqrt(pow(rx - all_structs->player.x * WIDTH_BLOCK, 2) \
		+ pow(ry - all_structs->player.y * HEIGHT_BLOCK, 2));
	return (length);
}

void	choose_west_or_east(t_all_structs *all_structs, double x, \
	double y, double angle)
{
	if (y > all_structs->player.y * HEIGHT_BLOCK)
		print_west(all_structs, x, y, angle);
	else
		print_est(all_structs, x, y, angle);
}

void	choose_south_or_north(t_all_structs *all_structs, double x, \
	double y, double angle)
{
	if (x > all_structs->player.x * HEIGHT_BLOCK)
		print_south(all_structs, x, y, angle);
	else
		print_north(all_structs, x, y, angle);
}
