/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 00:14:22 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/02/01 11:33:32 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../cub3d.h"

void	camera_direction(t_all_structs *all_structs);
void	movement(t_player *player, t_settings *settings, double angle, int neg);

int	key_hook(t_all_structs *all_structs)
{
	if (all_structs->keycode.left_arrow == TRUE
		|| all_structs->keycode.right_arrow == TRUE)
		camera_direction(all_structs);
	if (all_structs->keycode.a == TRUE)
		movement(&all_structs->player, &all_structs->settings, (PI / 2), 1);
	if (all_structs->keycode.d == TRUE)
		movement(&all_structs->player, &all_structs->settings, (PI / -2), 1);
	if (all_structs->keycode.w == TRUE)
		movement(&all_structs->player, &all_structs->settings, 0, 1);
	if (all_structs->keycode.s == TRUE)
		movement(&all_structs->player, &all_structs->settings, 0, -1);
	make_new_image(all_structs);
	return (0);
}

void	camera_direction(t_all_structs *all_structs)
{
	if (all_structs->keycode.left_arrow == TRUE)
	{
		all_structs->player.angle -= 0.025;
		if (all_structs->player.angle < 0)
			all_structs->player.angle += 2 * PI;
	}
	if (all_structs->keycode.right_arrow == TRUE)
	{
		all_structs->player.angle += 0.025;
		if (all_structs->player.angle > 2 * PI)
			all_structs->player.angle -= 2 * PI;
	}
}

void	movement(t_player *player, t_settings *settings, double angle, int neg)
{
	double	turn;

	turn = 0.6;
	if (settings->map[(int)player->y] \
	[(int)(player->x + cos(player->angle - angle) * neg * DIST)] != '1' \
	&& settings->map[(int)player->y] \
	[(int)(player->x + cos(player->angle + turn - angle) * neg * DIST)] != '1' \
	&& settings->map[(int)player->y] \
	[(int)(player->x + cos(player->angle - turn - angle) * neg * DIST)] != '1')
		player->x += cos(player->angle - angle) * neg * SPEED;
	if (settings->map[(int)(player->y + sin(player->angle - angle) \
	* neg * DIST)][(int)player->x] != '1' \
	&& settings->map[(int)(player->y + sin(player->angle + turn - angle) \
	* neg * DIST)][(int)player->x] != '1' \
	&& settings->map[(int)(player->y + sin(player->angle - turn - angle) \
	* neg * DIST)][(int)player->x] != '1')
		player->y += sin(player->angle - angle) * neg * SPEED;
}
