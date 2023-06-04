/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_palyer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:28:57 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/09 19:29:00 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"../../cub3d.h"

void	define_player(t_player *player);
void	set_position(t_all_structs *all_structs, char direction, int y, int x);
int		check_char_0(char **map, int x, int y);
int		check_player_exist(t_all_structs *all_structs, char c);

// This function allows to know all the information of the player.
void	set_info_palyer(t_all_structs *all_structs, char **map)
{
	t_player	player;
	int			y;
	int			x;

	y = 0;
	x = 0;
	define_player(&player);
	all_structs->player = player;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' \
				|| map[y][x] == 'W' || map[y][x] == 'E')
				set_position(all_structs, map[y][x], y, x);
			x++;
		}
		x = 0;
		y++;
	}
	if (check_player_exist(all_structs, all_structs->player.direction) && \
		check_char_0(map, all_structs->player.y, all_structs->player.x))
		error_map_not_closed(all_structs);
}

// This function allows to add information in the player structure.
void	set_position(t_all_structs *all_structs, char direction, int y, int x)
{
	if (all_structs->player.direction != '\0')
		error_player_already_set(all_structs);
	all_structs->player.direction = direction;
	all_structs->player.y = y;
	all_structs->player.x = x;
}

// This function allows to initialize to 0 the position of the player.
void	define_player(t_player *player)
{
	player->direction = '\0';
	player->x = 0;
	player->y = 0;
}

// This function allows to know if there is a palyer on the map.
int	check_player_exist(t_all_structs *all_structs, char c)
{
	if (c == '\0')
		error_player_not_exist(all_structs);
	return (1);
}
