/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:13:16 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/04/11 19:20:29 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*str;
	size_t	i;

	if (elementCount > 2147483647 || elementSize > 2147483647 || \
	elementCount * elementSize > 2147483647)
		return (NULL);
	i = -1;
	str = malloc(elementCount * elementSize);
	if (!str)
		return (NULL);
	while (++i < (elementCount * elementSize))
		str[i] = '\0';
	return (str);
}
