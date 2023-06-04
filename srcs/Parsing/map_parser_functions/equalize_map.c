/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equalize_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:31:56 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/09 19:31:57 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../cub3d.h"

char	*equalize_str(t_all_structs *all_structs, char *source, \
	int max_len);
int		set_max_len(char **map);
int		get_heigth_map(char **map);

// This function allows you to egualize a map by making it rectangular.
void	equalize_map(t_all_structs *all_structs, char **map)
{
	int	i;
	int	max_len;

	i = 0;
	max_len = set_max_len(map);
	all_structs->settings.length_map = max_len;
	all_structs->settings.heigth_map = get_heigth_map(map);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) < max_len)
			map[i] = equalize_str(all_structs, map[i], max_len);
		i++;
	}
}

// This function allows to know the largest len of the double array.
int	set_max_len(char **map)
{
	int	i;
	int	len;
	int	max_len;

	i = 0;
	len = 0;
	max_len = 0;
	while (map[i] != NULL)
	{
		len = ft_strlen(map[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (max_len);
}

// This function allows to egualize a string with ' '.
char	*equalize_str(t_all_structs *all_structs, char *source, int max_len)
{
	char	*dest;
	int		i;

	(void)all_structs;
	i = 0;
	dest = malloc(sizeof(char) * (max_len + 1));
	if (!dest)
		error_malloc(&all_structs->settings);
	while (source[i] != '\0')
	{
		dest[i] = source[i];
		i++;
	}
	while (i < max_len)
	{
		dest[i] = ' ';
		i++;
	}
	dest[i] = '\0';
	free(source);
	return (dest);
}

int	get_heigth_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}
