/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:40:26 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/02/01 00:40:28 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../cub3d.h"

void	error_bad_extension(t_settings *settings);

void	check_extension(t_settings *settings)
{
	int	len;

	len = ft_strlen(settings->map_name);
	if (len < 5)
		error_bad_extension(settings);
	if (settings->map_name[len - 1] == 'b')
		if (settings->map_name[len - 2] == 'u')
			if (settings->map_name[len - 3] == 'c')
				if (settings->map_name[len - 4] == '.')
					if (settings->map_name[len - 5] != '/')
						return ;
	error_bad_extension(settings);
}

void	error_bad_extension(t_settings *settings)
{
	write(2, "Error\n", 6);
	write(2, "Bad extension, use -> .cub.\n", 28);
	free_settings_struct(settings);
	exit(EXIT_FAILURE);
}
