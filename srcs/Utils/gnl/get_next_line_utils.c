/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:01:22 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/04/27 20:01:32 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include	"../../cub3d.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (free(s1), NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + BUFFER_SIZE + 1));
	if (!dest)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[++j])
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
	free(s1);
	s1 = 0;
	return (dest);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_do_strjoin(int i, char *buf, char *save)
{
	buf[i] = 0;
	return (ft_strjoin(save, buf));
}	
