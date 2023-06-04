/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:27:38 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/05/23 16:10:05 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c, int a)
{
	static int	i = 0;

	if (a == RESET)
		i = 0;
	else if (a == PRINT)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int	ft_check_param(const char s, va_list ptr)
{
	if (s == 'c')
		ft_putchar(va_arg(ptr, int), PRINT);
	if (s == 's')
		ft_putstr(va_arg(ptr, char *));
	if (s == 'p')
		ft_void(va_arg(ptr, unsigned long long));
	if (s == 'd')
		ft_putnbr(va_arg(ptr, int));
	if (s == 'i')
		ft_putnbr(va_arg(ptr, int));
	if (s == 'u')
		ft_putnbru(va_arg(ptr, unsigned int));
	if (s == 'x')
		ft_put_hexa("0123456789abcdef", va_arg(ptr, unsigned int));
	if (s == 'X')
		ft_put_hexa("0123456789ABCDEF", va_arg(ptr, unsigned int));
	if (s == '%')
		ft_putchar('%', PRINT);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	ptr;

	i = -1;
	va_start(ptr, s);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			i++;
			ft_check_param(s[i], ptr);
		}
		else
			ft_putchar(s[i], PRINT);
	}
	va_end(ptr);
	len = ft_putchar('a', RETURN);
	ft_putchar('a', RESET);
	return (len);
}
