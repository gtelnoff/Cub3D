/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_have_all_params.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:29:33 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/12 20:29:36 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"../../cub3d.h"

int		is_params(char *params);
void	error_unknown_params(t_settings *settings, char **params, char *name);

// This function allows to know if there is no unknown parameter.
void	check_have_unknow_params(t_settings *settings, char **params)
{
	int	i;

	i = 0;
	while (params[i] != NULL)
	{
		if (!is_params(params[i]))
			error_unknown_params(settings, params, params[i]);
		i++;
	}
}

// This function allows to know if the string is a parameter or not.
int	is_params(char *params)
{
	if (!ft_strncmp(params, "NO ", 3))
		return (1);
	else if (!ft_strncmp(params, "SO ", 3))
		return (1);
	else if (!ft_strncmp(params, "WE ", 3))
		return (1);
	else if (!ft_strncmp(params, "EA ", 3))
		return (1);
	else if (!ft_strncmp(params, "F ", 2))
		return (1);
	else if (!ft_strncmp(params, "C ", 2))
		return (1);
	else
		return (0);
	return (1);
}
