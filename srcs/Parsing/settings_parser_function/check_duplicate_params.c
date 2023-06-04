/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate_params.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:07:56 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/12 22:08:02 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"../../cub3d.h"

int		is_params(char *params);
char	*set_info_params(t_settings *settings, \
	char **all_params, char *params, char *params_content);
void	error_settings_already_set(t_settings *settings, \
	char **allparams, char *params);
void	assign_params(t_settings *settings, char **all_params, char *params);
void	define_null_addr(t_settings *settings);

// This function allows you to know if any of the parameters appear twice.
void	check_duplicate_params(t_settings *settings, char **params)
{
	int	i;

	i = 0;
	while (params[i] != NULL)
	{
		assign_params(settings, params, params[i]);
		i++;
	}
}

// This function allows to know what is the parameter to set.
void	assign_params(t_settings *settings, char **all_params, char *params)
{
	if (!ft_strncmp(params, "NO ", 3))
		settings->texture[0].addr_texture = \
			set_info_params(settings, all_params, params, \
				settings->texture[0].addr_texture);
	else if (!ft_strncmp(params, "SO ", 3))
		settings->texture[1].addr_texture = \
			set_info_params(settings, all_params, params, \
				settings->texture[1].addr_texture);
	else if (!ft_strncmp(params, "WE ", 3))
		settings->texture[2].addr_texture = \
			set_info_params(settings, all_params, params, \
				settings->texture[2].addr_texture);
	else if (!ft_strncmp(params, "EA ", 3))
		settings->texture[3].addr_texture = \
			set_info_params(settings, all_params, params, \
				settings->texture[3].addr_texture);
}

// This function allows to generate a string with the parameter information.
char	*set_info_params(t_settings *settings, \
	char **all_params, char *params, char *params_content)
{
	char	*new_params;

	if (params_content != NULL)
		error_settings_already_set(settings, all_params, params);
	new_params = ft_strdup(params);
	new_params = ft_trunc_str(new_params, 3);
	new_params = ft_strtrim_free(new_params, " ");
	return (new_params);
}

void	define_null_addr(t_settings *settings)
{
	settings->texture[0].addr_texture = NULL;
	settings->texture[1].addr_texture = NULL;
	settings->texture[2].addr_texture = NULL;
	settings->texture[3].addr_texture = NULL;
	settings->texture[0].image = NULL;
	settings->texture[1].image = NULL;
	settings->texture[2].image = NULL;
	settings->texture[3].image = NULL;
}
