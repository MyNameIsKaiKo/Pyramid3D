/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 11:54:46 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/10 13:29:13 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static int	check_format(char *color)
{
	int	check_color;
	int	i;

	i = 0;
	while (color[i])
	{
		if (!ft_isdigit(color[i]))
			return (print_error("Format of color is invalid"));
		i++;
	}
	check_color = ft_atoi(color);
	if (check_color < 0 || check_color > 255)
		return (print_error("Color is invalid"));
	return (0);
}

static int	valid_color(char **tab_color)
{
	int		i;

	i = 0;
	while (tab_color[i])
	{
		if (check_format(tab_color[i]) > 0)
			return (1);
		i++;
	}
	if (i != 3)
		return (print_error("Color is invalid"));
	return (0);
}

int	parse_color(char **color)
{
	char	**tab_color;
	int		index_color;

	index_color = NB_TEXTURES;
	while (index_color < NB_ALL_TEXTURES)
	{
		tab_color = ft_split(color[index_color], ',');
		if (!tab_color)
			return (print_error("Malloc failed"));
		if (valid_color(tab_color) > 0)
		{
			free_matrix(tab_color);
			return (1);
		}
		index_color++;
		free_matrix(tab_color);
	}
	return (0);
}
