/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:53:10 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/05/05 22:43:10 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include "../../cub3d.h"

char	*ft_get_new_save(char *save)
{
	char	*new_save;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (save[i])
	{
		if (save[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	new_save = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	while (save[i])
		new_save[x++] = save[i++];
	new_save[x] = '\0';
	free(save);
	save = 0;
	return (new_save);
}

char	*ft_get_new_line(char *save)
{
	char	*newline;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (save[i])
	{
		if (save[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	newline = malloc(sizeof(char) * (i + 1));
	while (x < i)
	{
		newline[x] = save[x];
		x++;
	}
	newline[x] = '\0';
	return (newline);
}

int	ft_its_new_line(char *save)
{
	int	i;

	i = -1;
	while (save[++i])
		if (save[i] == '\n')
			return (1);
	return (0);
}

char	*do_save(char *save)
{
	save = malloc(1);
	save[0] = '\0';
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	int			i;

	i = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf || fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (free(buf), NULL);
	if (!save)
		save = do_save(save);
	while (!ft_its_new_line(save) && i)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 1 && (save == NULL || ft_strlen(save) == 0))
		{
			free(save);
			save = NULL;
			return (free(buf), NULL);
		}
		save = ft_do_strjoin(i, buf, save);
	}
	free(buf);
	buf = ft_get_new_line(save);
	save = ft_get_new_save(save);
	return (buf);
}
