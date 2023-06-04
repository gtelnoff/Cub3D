/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rx_ry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 01:53:20 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/02/01 01:53:21 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_rx_ry(t_all_structs *all_structs, double *ray_x, double *ray_y)
{
	all_structs->player.count++;
	free(ray_x);
	free(ray_y);
}
