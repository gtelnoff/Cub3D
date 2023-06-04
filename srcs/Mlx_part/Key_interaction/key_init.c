/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:04:00 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/02/01 11:43:41 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	key_init(t_all_structs *all_structs)
{
	all_structs->keycode.w = FALSE;
	all_structs->keycode.a = FALSE;
	all_structs->keycode.s = FALSE;
	all_structs->keycode.d = FALSE;
	all_structs->keycode.left_arrow = FALSE;
	all_structs->keycode.right_arrow = FALSE;
	all_structs->player.speed = 0;
}
