/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:57:32 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/30 23:57:33 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	set_line(t_all_structs *all_structs, double end, int nbr);

void	draw_wall(t_all_structs *all_structs, \
	double height, double end, int nbr)
{
	double	line;
	double	color_count;
	int		middle;
	int		color;
	int		y;

	middle = (int)(height) / 2;
	line = set_line(all_structs, end, nbr);
	color_count = all_structs->settings.texture[nbr].heigth / height;
	y = (WIN_SIZE_Y / 2) - middle;
	while (y < (WIN_SIZE_Y / 2) + middle)
	{
		if (y >= 0 && y <= WIN_SIZE_Y)
		{
			color = my_get_color_pixel(&all_structs->settings, \
				line, color_count, nbr);
			my_mlx_pixel_put(&all_structs->mlx, all_structs->player.count, \
				y, color);
		}
		color_count += (all_structs->settings.texture[nbr].heigth / height);
		y++;
	}
}

void	print_north(t_all_structs *all_structs, \
	double end_px, double end_py, double angle)
{
	double	lenght;
	double	height;
	double	comb;

	lenght = sqrt(pow(end_px - all_structs->player.x * WIDTH_BLOCK, 2) \
	+ pow(end_py - all_structs->player.y * HEIGHT_BLOCK, 2));
	comb = all_structs->player.angle - angle;
	comb = fix_pi(comb);
	lenght *= cosf(comb);
	height = 32 / lenght * 930;
	draw_wall(all_structs, height, end_py, 3);
}

void	print_south(t_all_structs *all_structs, \
	double end_px, double end_py, double angle)
{
	double	lenght;
	double	height;
	double	comb;

	lenght = sqrt(pow(end_px - all_structs->player.x * WIDTH_BLOCK, 2) \
	+ pow(end_py - all_structs->player.y * HEIGHT_BLOCK, 2));
	comb = all_structs->player.angle - angle;
	comb = fix_pi(comb);
	lenght *= cosf(comb);
	height = 32 / lenght * 930;
	draw_wall(all_structs, height, end_py, 2);
}

void	print_west(t_all_structs *all_structs, \
	double end_px, double end_py, double angle)
{
	double	lenght;
	double	height;
	double	comb;

	lenght = sqrt(pow(end_px - all_structs->player.x * WIDTH_BLOCK, 2) \
	+ pow(end_py - all_structs->player.y * HEIGHT_BLOCK, 2));
	comb = all_structs->player.angle - angle;
	comb = fix_pi(comb);
	lenght *= cosf(comb);
	height = 32 / lenght * 930;
	draw_wall(all_structs, height, end_px, 0);
}

void	print_est(t_all_structs *all_structs, \
	double end_px, double end_py, double angle)
{
	double	lenght;
	double	height;
	double	comb;

	lenght = sqrt(pow(end_px - all_structs->player.x * WIDTH_BLOCK, 2) \
	+ pow(end_py - all_structs->player.y * HEIGHT_BLOCK, 2));
	comb = all_structs->player.angle - angle;
	comb = fix_pi(comb);
	lenght *= cosf(comb);
	height = 32 / lenght * 930;
	draw_wall(all_structs, height, end_px, 1);
}
