/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:18:28 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/05/23 16:10:08 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../cub3d.h"
# include <stdarg.h>
# define RETURN 1
# define PRINT 0
# define RESET -1

int		ft_check_param(const char s, va_list ptr);
int		ft_printf(const char *s, ...);
int		ft_putchar(char c, int a);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_put_hexa(char *hexa, unsigned long long n);
void	ft_putnbru(unsigned int n);
void	ft_void(unsigned long long n);

#endif
