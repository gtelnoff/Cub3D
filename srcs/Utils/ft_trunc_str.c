/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_truncstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:10:26 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/08 16:10:27 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

char	*ft_trunc_str(char *str, int start)
{
	char	*new_str;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if ((ft_strlen(str) - start) <= 0)
		return (NULL);
	new_str = malloc(sizeof(char *) * (ft_strlen(str) - start));
	if (!new_str)
		return (NULL);
	while (i < start)
		i++;
	while (str[i] != '\0')
	{
		new_str[x] = str[i];
		x++;
		i++;
	}
	new_str[x] = '\0';
	free(str);
	return (new_str);
}
