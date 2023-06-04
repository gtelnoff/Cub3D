/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 02:04:53 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/02/01 02:04:54 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	set_line(t_all_structs *all_structs, double end, int nbr)
{
	double	line;

	line = (end - (double)((int)(end / 32) *32.0));
	if (nbr == 1 || nbr == 3)
		line = line * all_structs->settings.texture[nbr].width / BLOCK;
	else if (nbr == 0 || nbr == 2)
	{
		line = line * all_structs->settings.texture[nbr].width / BLOCK;
		line = all_structs->settings.texture[nbr].width - line;
	}
	return (line);
}
