/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:16:50 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/04/06 18:51:27 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signe;
	int	nbr;

	i = -1;
	signe = 0;
	nbr = 0;
	while (nptr[i + 1] == ' ' || (nptr[i + 1] >= '\t' && nptr[i + 1] <= '\r'))
		i++;
	if (nptr[i + 1] == '-' || nptr[i + 1] == '+')
	{
		if (nptr[i + 1] == '-')
			signe = 1;
		i++;
	}
	while (nptr[++i] >= '0' && nptr[i] <= '9')
	{
		nbr *= 10;
		nbr += nptr[i] - '0';
	}
	if (signe == 1)
		nbr *= -1;
	return (nbr);
}
