/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:55:13 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/09 19:55:15 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

int	is_space(char *str);

char	**set_new_map(t_settings *settings, char **map)
{
	char	**new_map;
	int		start;
	int		len;
	int		i;

	(void)settings;
	if (map == NULL)
		exit(EXIT_FAILURE);
	start = 0;
	i = 0;
	len = get_len_2d_array(map) - 1;
	while (is_space(map[start]))
		start++;
	while (is_space(map[len]))
		len--;
	new_map = malloc(sizeof(char *) * (len - start + 2));
	while (start <= len)
	{
		new_map[i] = ft_strdup(map[start]);
		start++;
		i++;
	}
	new_map[i] = NULL;
	free_2d_array(map);
	return (new_map);
}

int	is_space(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != '\n' && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
