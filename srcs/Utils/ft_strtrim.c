/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:48:18 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/04/26 13:21:34 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

static int	start(char s1, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (s1 == set[i])
			return (1);
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*dest;
	size_t	i;
	size_t	a;
	size_t	lenmax;

	i = -1;
	a = 0;
	if (!s1)
		return (NULL);
	lenmax = ft_strlen(s1);
	while (start(s1[++i], set))
		a++;
	while (start(s1[lenmax - 1], set))
		--lenmax;
	if (s1[a] == 0 && a > lenmax)
		a = lenmax;
	dest = malloc(sizeof(char) * (lenmax - a + 1));
	if (!dest)
		return (0);
	i = 0;
	while (a < lenmax)
		dest[i++] = s1[a++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim_free(char *s1, char *set)
{
	char	*dest;
	size_t	i;
	size_t	a;
	size_t	lenmax;

	i = -1;
	a = 0;
	if (!s1)
		return (NULL);
	lenmax = ft_strlen(s1);
	while (start(s1[++i], set))
		a++;
	while (start(s1[lenmax - 1], set))
		--lenmax;
	if (s1[a] == 0 && a > lenmax)
		a = lenmax;
	dest = malloc(sizeof(char) * (lenmax - a + 1));
	if (!dest)
		return (0);
	i = 0;
	while (a < lenmax)
		dest[i++] = s1[a++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}
