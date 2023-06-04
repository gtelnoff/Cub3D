/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 00:11:23 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/31 00:11:25 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	key_release(int key, t_all_structs *all_structs)
{
	if (key == 'w')
		all_structs->keycode.w = FALSE;
	if (key == 'a')
		all_structs->keycode.a = FALSE;
	if (key == 's')
		all_structs->keycode.s = FALSE;
	if (key == 'd')
		all_structs->keycode.d = FALSE;
	if (key == 65361)
		all_structs->keycode.left_arrow = FALSE;
	if (key == 65363)
		all_structs->keycode.right_arrow = FALSE;
	return (0);
}
