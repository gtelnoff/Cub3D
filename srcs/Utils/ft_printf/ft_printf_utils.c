/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:55:38 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/05/12 15:55:41 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	if (!str)
	{
		ft_putstr("(null)");
		return ;
	}
	while (str[++i])
		ft_putchar(str[i], PRINT);
}

void	ft_putnbr(int n)
{
	if (n == (-2147483648))
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', PRINT);
		ft_putnbr(n * (-1));
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar('0' + n % 10, PRINT);
	}
	else
		ft_putchar(n + '0', PRINT);
}

void	ft_putnbru(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar('0' + n % 10, PRINT);
	}
	else
		ft_putchar(n + '0', PRINT);
}

void	ft_put_hexa(char *hexa, unsigned long long n)
{	
	if (n >= 16)
	{
		ft_put_hexa(hexa, n / 16);
		ft_putchar(hexa[n % 16], PRINT);
	}
	else
		ft_putchar(hexa[n], PRINT);
}

void	ft_void(unsigned long long n)
{
	if (n == 0)
	{
		ft_putstr("(nil)");
		return ;
	}
	ft_putstr("0x");
	ft_put_hexa("0123456789abcdef", n);
}
