/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:05:59 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/04/26 12:30:14 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;
	size_t	lengthbis;

	i = 0;
	lengthbis = length;
	if (length <= 0)
		return (0);
	while (first[i] && (first[i] == second[i]) && (i < lengthbis - 1))
		i++;
	return ((unsigned char)first[i] - (unsigned char)second[i]);
}
