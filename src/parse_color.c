/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 16:27:40 by ldepenne          #+#    #+#             */
/*   Updated: 2026/06/29 16:31:08 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

static int	valid_color(char **tab_color)
{
	int		check_color;
	int		i;

	i = 0;
	while (tab_color[i])
	{
		check_color = ft_atoi(tab_color[i]);
		if (check_color < 0 || check_color > 255)
		{
			print_error("Color is invalid");
			return (1);
		}
		i++;
	}
	if (i != 3)
	{
		print_error("Color is invalid");
		return (1);
	}
	return (0);
}

int	parse_color(char **color)
{
	char	**tab_color;
	int		index_color;

	index_color = NB_PATH_TEXTURES;
	while (index_color < NB_ALL_TEXTURES)
	{
		tab_color = ft_split(color[index_color], ',');
		if (!tab_color)
		{
			print_error("Malloc failed");
			return (1);
		}
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
