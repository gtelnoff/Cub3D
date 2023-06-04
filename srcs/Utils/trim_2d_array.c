/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_2d_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:46:21 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/09 19:46:51 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

char	**trim_2d_array(char **array, char *set)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		array[i] = ft_strtrim_free(array[i], set);
		i++;
	}
	return (array);
}
