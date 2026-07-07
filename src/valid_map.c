/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 18:48:57 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/07 13:43:49 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

int	valid_rcolumn_border(char **tab_map, size_t height)
{
	size_t	i;
	int		top_wall;
	int		bottom_wall;

	i = ft_strlen(tab_map[height]) - 1;
	top_wall = 0;
	bottom_wall = 0;
	while (tab_map[height][i] && tab_map[height][i] == EMPTY)
		i--;
	while (tab_map[height][i] && tab_map[height][i] == WALL)
	{
		if (ft_strlen(tab_map[height - 1]) >= i
			&& tab_map[height - 1][i] == WALL)
			top_wall = 1;
		if (ft_strlen(tab_map[height + 1]) >= i
			&& tab_map[height + 1][i] == WALL)
			bottom_wall = 1;
		if (top_wall == 1 && bottom_wall == 1)
			return (0);
		else
			i--;
	}
	return (print_error("The map is open"));
}

int	valid_lcolumn_border(char **tab_map, size_t height)
{
	size_t	i;
	int		top_wall;
	int		bottom_wall;

	i = 0;
	top_wall = 0;
	bottom_wall = 0;
	while (tab_map[height][i] && tab_map[height][i] == EMPTY)
		i++;
	while (tab_map[height][i] && tab_map[height][i] == WALL)
	{
		if (ft_strlen(tab_map[height - 1]) >= i
			&& tab_map[height - 1][i] == WALL)
			top_wall = 1;
		if (ft_strlen(tab_map[height + 1]) >= i
			&& tab_map[height + 1][i] == WALL)
			bottom_wall = 1;
		if (top_wall == 1 && bottom_wall == 1)
			return (0);
		else
			i++;
	}
	return (print_error("The map is open"));
}

int	valid_border_line(char **tab_map, size_t max_height)
{
	size_t	i;

	i = 0;
	while (tab_map[0][i])
	{
		if (!(tab_map[0][i] == EMPTY || tab_map[0][i] == WALL))
			return (print_error("A border line is incorrect"));
		i++;
	}
	i = 0;
	while (tab_map[max_height][i])
	{
		if (!(tab_map[max_height][i] == EMPTY
			|| tab_map[max_height][i] == WALL))
			return (print_error("A border line is incorrect"));
		i++;
	}
	if (tab_map[max_height][i]
		&& !(tab_map[max_height][i] == EMPTY || tab_map[max_height][i] == WALL))
		return (print_error("A border line is incorrect"));
	return (0);
}
