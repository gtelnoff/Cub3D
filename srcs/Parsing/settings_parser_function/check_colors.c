/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:41:11 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/01/12 23:41:12 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"../../cub3d.h"

void	error_settings_already_set(t_settings *settings, \
	char **all_params, char *params);
void	error_empty_params(t_settings *settings, char **params);
void	error_colors_format(t_settings *settings, \
	char **all_params, char *params);
void	set_colors(t_settings *settings, \
	char **all_params, char *params, int *params_content);
void	check_format(t_settings *settings, \
		char **all_params, char *params);
void	check_split_params(t_settings *settings, \
	char **all_params, char **new_params, char *params);
int		check_rgb_numbers(int *rgb);

// This function allows you to set,
// the ceiling and floor colors in the structure settings.
void	check_colors(t_settings *settings, char **params)
{
	int	i;

	i = 0;
	while (params[i] != NULL)
	{
		if (!ft_strncmp("C ", params[i], 2))
			set_colors(settings, params, params[i], settings->ceiling_color);
		else if (!ft_strncmp("F ", params[i], 2))
			set_colors(settings, params, params[i], settings->floor_color);
		i++;
	}
}

// This function allows to prepare a double table to check the RGB format.
void	set_colors(t_settings *settings, char **all_params, \
	char *params, int *params_content)
{
	char	**split_params;
	char	*new_params;

	if (params_content != NULL)
		error_settings_already_set(settings, all_params, params);
	check_format(settings, all_params, params);
	new_params = ft_strdup(params);
	new_params = ft_trunc_str(new_params, 2);
	new_params = ft_strtrim_free(new_params, " ");
	split_params = ft_split(new_params, ',');
	if (split_params[0] == NULL \
	|| split_params[1] == NULL \
	|| split_params[2] == NULL)
	{
		free_2d_array(split_params);
		free(new_params);
		error_colors_format(settings, all_params, params);
	}
	free(new_params);
	check_split_params(settings, all_params, split_params, params);
	free_2d_array(split_params);
}

// This function allows to check if the RGB format (255,255,255) is respected.
void	check_format(t_settings *settings, char **all_params, char *params)
{
	int	i;
	int	nb_of_comma;

	i = 1;
	nb_of_comma = 0;
	while (params[i] == ' ')
		i++;
	while (params[i] != '\0')
	{
		if ((params[i] < '0' || params[i] > '9') && params[i] != ',')
			error_colors_format(settings, all_params, params);
		if (params[i] == ',')
			nb_of_comma++;
		i++;
	}
	if (nb_of_comma != 2)
		error_colors_format(settings, all_params, params);
}

// This function also allows to check if,
// the RGB format (255,255,255) is respected.
void	check_split_params(t_settings *settings, \
	char **all_params, char **new_params, char *params)
{
	int	*rgb;

	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
		error_malloc(settings);
	rgb[0] = ft_atoi(new_params[0]);
	rgb[1] = ft_atoi(new_params[1]);
	rgb[2] = ft_atoi(new_params[2]);
	if (!check_rgb_numbers(rgb))
	{
		free(rgb);
		free_2d_array(new_params);
		error_colors_format(settings, all_params, params);
	}
	if (!ft_strncmp("C ", params, 2))
			settings->ceiling_color = rgb;
	else if (!ft_strncmp("F ", params, 2))
			settings->floor_color = rgb;
}

// This function lets you know,
// if the rgb numbers are neither too big nor too small.
int	check_rgb_numbers(int *rgb)
{
	if (rgb[0] > 255 || rgb[0] < 0)
		return (0);
	else if (rgb[1] > 255 || rgb[1] < 0)
		return (0);
	else if (rgb[2] > 255 || rgb[2] < 0)
		return (0);
	return (1);
}
