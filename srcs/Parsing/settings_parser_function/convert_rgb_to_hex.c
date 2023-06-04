/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb_to_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:42:47 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/31 16:42:48 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../cub3d.h"

void	convert_rgb_to_hex(t_settings *settings)
{
	int	color_buff;

	color_buff = 0;
	color_buff = settings->ceiling_color[0] << 16;
	color_buff |= settings->ceiling_color[1] << 8;
	color_buff |= settings->ceiling_color[2];
	settings->ceiling_color[0] = color_buff;
	color_buff = 0;
	color_buff = settings->floor_color[0] << 16;
	color_buff |= settings->floor_color[1] << 8;
	color_buff |= settings->floor_color[2];
	settings->floor_color[0] = color_buff;
}
