/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:18:28 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/05/10 19:16:12 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<fcntl.h>
# define BUFFER_SIZE 150

char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_get_new_save(char *save);
char	*ft_get_new_line(char *save);
char	*ft_do_strjoin(int i, char *buf, char *save);
char	*do_save(char *save);
int		ft_its_new_line(char *save);
int		ft_strlen(char *s);

#endif
