/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:26:29 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/08 14:26:34 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"../cub3d.h"

char	*ft_strdup(char *source)
{
	char	*dest;
	char	*sourcebis;
	int		i;

	dest = malloc(sizeof(char) * (ft_strlen(source) + 1));
	if (!dest)
		return (NULL);
	sourcebis = source;
	i = -1;
	while (source[++i])
		dest[i] = sourcebis[i];
	dest[i] = '\0';
	return (dest);
}
