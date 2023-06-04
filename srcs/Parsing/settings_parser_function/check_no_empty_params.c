/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:08:18 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/12 19:09:36 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"../../cub3d.h"

int		have_just_params_id(char *params);
int		have_params_and_space(char *params);
int		have_only_space(char *params);
void	write_error(char *name_params);
void	error_empty_params(t_settings *settings, char **params);

// This function allows to know if there is no empty parameter.
void	check_no_empty_params(t_settings *settings, char **params)
{
	int	i;

	i = 0;
	while (params[i] != NULL)
	{
		if (have_just_params_id(params[i]) || have_params_and_space(params[i]))
			error_empty_params(settings, params);
		i++;
	}
}

// This function allows to know if there is no empty parameter.
int	have_just_params_id(char *params)
{
	if (!ft_strncmp(params, "NO\n", 3))
		write_error("NO");
	else if (!ft_strncmp(params, "SO\n", 3))
		write_error("SO");
	else if (!ft_strncmp(params, "WE\n", 3))
		write_error("WE");
	else if (!ft_strncmp(params, "EA\n", 3))
		write_error("EA");
	else if (!ft_strncmp(params, "F\n", 2))
		write_error("F");
	else if (!ft_strncmp(params, "C\n", 2))
		write_error("C");
	else
		return (0);
	return (1);
}

// This function allows to know if there is no empty parameter.
int	have_params_and_space(char *params)
{
	if (!ft_strncmp(params, "NO ", 3) && have_only_space(params))
		write_error("NO");
	else if (!ft_strncmp(params, "SO ", 3) && have_only_space(params))
		write_error("SO");
	else if (!ft_strncmp(params, "WE ", 3) && have_only_space(params))
		write_error("WE");
	else if (!ft_strncmp(params, "EA ", 3) && have_only_space(params))
		write_error("EA");
	else if (!ft_strncmp(params, "F ", 2) && have_only_space(params))
		write_error("F");
	else if (!ft_strncmp(params, "C ", 2) && have_only_space(params))
		write_error("C");
	else
		return (0);
	return (1);
}

int	have_only_space(char *params)
{
	int	i;

	i = 0;
	while (params[i] != ' ')
		i++;
	while (params[i] != '\n')
	{
		if (params[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	write_error(char *name_params)
{
	write(2, "Error\n'", 7);
	ft_putstr_fd(name_params, 2);
	write(2, "': Empty params.\n", 17);
}
