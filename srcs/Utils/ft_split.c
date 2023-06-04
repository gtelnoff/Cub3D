/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:03:44 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/04/26 13:08:53 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

static int	countab(char *s, char c)
{
	int	i;
	int	ntab;

	i = 0;
	ntab = 0;
	while (i < ft_strlen(s) && s[i] == c)
		i++;
	while (i < ft_strlen(s) && s[i])
	{
		if ((s[i] == c && s[i + 1] != c) || s[i + 1] == '\0')
			ntab++;
		i++;
	}
	return (ntab);
}

static unsigned int	countchar(char *s, char c, unsigned int x)
{
	unsigned int	i;

	i = 0;
	while (s[x] != c && s[x] != '\0')
	{
		i++;
		x++;
	}
	return (i);
}

char	**ft_split(char *s, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	index;
	unsigned int	ntab;

	if (!s)
		return (NULL);
	ntab = countab(s, c);
	tab = ft_calloc(sizeof(char *), (ntab + 1));
	if (!tab)
		return (NULL);
	i = 0;
	index = 0;
	while (ntab > 0)
	{
		while (s[i] == c)
			i++;
		tab[index] = ft_substr(s, i, countchar(s, c, i));
		while (s[i] != c && s[i] != '\0')
			i++;
		ntab--;
		index++;
	}
	return (tab);
}
