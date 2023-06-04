/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:51:56 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/04/26 13:20:25 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*sbis;
	char	*dest;
	int		i;
	int		j;

	sbis = s;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		dest = malloc(sizeof(char) * 1);
		*dest = '\0';
		return (dest);
	}
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = start;
	while (i < len)
		dest[i++] = sbis[j++];
	dest[i] = '\0';
	return (dest);
}
