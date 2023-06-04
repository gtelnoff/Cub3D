/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:27:39 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/30 18:44:27 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				key_release(int key, t_all_structs *all_structs);
int				key_pressed(int key, t_all_structs *all_structs);
void			set_mlx(t_all_structs *all_structs);
void			key_init(t_all_structs *all_structs);
unsigned int	my_get_color_pixel(t_settings *settings, \
	int x, int y, int nbr);
void			set_info_player(t_all_structs *all_structs);
int				turn_off(t_all_structs *all_structs);

void	start_game(t_all_structs *all_structs)
{
	set_mlx(all_structs);
	key_init(all_structs);
	set_info_player(all_structs);
	all_structs->mlx.image = \
		mlx_new_image(all_structs->mlx.mlx, WIN_SIZE_X, WIN_SIZE_Y);
	all_structs->mlx.addr = \
		mlx_get_data_addr(all_structs->mlx.image, \
			&all_structs->mlx.bits_per_pixel, \
				&all_structs->mlx.line_length, &all_structs->mlx.endian);
	mlx_hook(all_structs->mlx.win, 2, 1L, key_pressed, all_structs);
	mlx_hook(all_structs->mlx.win, 3, 1L << 1, key_release, all_structs);
	mlx_hook(all_structs->mlx.win, 17, 1L << 2, turn_off, all_structs);
	mlx_loop_hook(all_structs->mlx.mlx, key_hook, all_structs);
	mlx_loop(all_structs->mlx.mlx);
}

void	set_info_player(t_all_structs *all_structs)
{
	char	**map;
	double	px;
	double	py;

	map = all_structs->settings.map;
	px = all_structs->player.x;
	py = all_structs->player.y;
	all_structs->player.pdx = 0.1;
	all_structs->player.pdy = 0;
	if (map[(int)py][(int)px] == 'N')
		all_structs->player.angle = 3 * PI / 2;
	else if (all_structs->settings.map[(int)py][(int)px] == 'S')
		all_structs->player.angle = 3 * 3 * PI / 2;
	else if (all_structs->settings.map[(int)py][(int)px] == 'W')
		all_structs->player.angle = 3 * PI;
	else
		all_structs->player.angle = 3 * 0;
}
