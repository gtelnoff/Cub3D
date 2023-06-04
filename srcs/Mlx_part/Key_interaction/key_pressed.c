/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 00:11:32 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/02/01 11:27:59 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	key_pressed(int key, t_all_structs *all_structs)
{
	if (key == XK_w && (all_structs->keycode.s == FALSE \
	|| all_structs->keycode.d == FALSE \
	|| all_structs->keycode.a == FALSE))
		all_structs->keycode.w = TRUE;
	if (key == XK_a && (all_structs->keycode.s == FALSE \
	|| all_structs->keycode.d == FALSE \
	|| all_structs->keycode.w == FALSE))
		all_structs->keycode.a = TRUE;
	if (key == XK_s && (all_structs->keycode.w == FALSE \
	|| all_structs->keycode.d == FALSE \
	|| all_structs->keycode.a == FALSE))
		all_structs->keycode.s = TRUE;
	if (key == XK_d && (all_structs->keycode.s == FALSE \
	|| all_structs->keycode.w == FALSE \
	|| all_structs->keycode.a == FALSE))
		all_structs->keycode.d = TRUE;
	if (key == XK_Left)
		all_structs->keycode.left_arrow = TRUE;
	if (key == XK_Right)
		all_structs->keycode.right_arrow = TRUE;
	if (key == XK_Escape)
		turn_off(all_structs);
	return (0);
}
