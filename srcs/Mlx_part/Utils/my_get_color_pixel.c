/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_get_color_pixel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:16:42 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/31 01:16:44 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

unsigned int	my_get_color_pixel(t_settings *settings, int x, int y, int nbr)
{
	char	*dst;

	dst = settings->texture[nbr].addr_texture + \
		(y * settings->texture[nbr].line_length + \
			x * (settings->texture[nbr].bits_per_pixel / 8));
	return (*(unsigned int *) dst);
}
