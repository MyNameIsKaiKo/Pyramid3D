/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 18:48:57 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/08 19:42:32 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	valid_rcolumn_border(char **map_tab, size_t height)
{
	size_t	i;
	int		top_wall;
	int		bottom_wall;

	i = ft_strlen(map_tab[height]) - 1;
	top_wall = 0;
	bottom_wall = 0;
	while (map_tab[height][i] && map_tab[height][i] == EMPTY)
		i--;
	while (map_tab[height][i] && map_tab[height][i] == WALL)
	{
		if (ft_strlen(map_tab[height - 1]) >= i
			&& (map_tab[height - 1][i] == WALL
			|| map_tab[height - 1][i - 1] == WALL))
			top_wall = 1;
		else if (ft_strlen(map_tab[height - 1]) > i
			&& map_tab[height - 1][i + 1] == WALL)
			top_wall = 1;
		if (ft_strlen(map_tab[height + 1]) >= i
			&& (map_tab[height + 1][i] == WALL
			|| map_tab[height + 1][i - 1] == WALL))
			bottom_wall = 1;
		else if (ft_strlen(map_tab[height + 1]) > i
			&& map_tab[height + 1][i + 1] == WALL)
			bottom_wall = 1;
		if (top_wall == 1 && bottom_wall == 1)
			return (0);
		else
			i--;
	}
	return (print_error("The map is open"));
}

int	valid_lcolumn_border(char **map_tab, size_t height)
{
	size_t	i;
	int		top_wall;
	int		bottom_wall;

	i = 0;
	top_wall = 0;
	bottom_wall = 0;
	while (map_tab[height][i] && map_tab[height][i] == EMPTY)
		i++;
	while (map_tab[height][i] && map_tab[height][i] == WALL)
	{
		if (ft_strlen(map_tab[height - 1]) >= i
			&& (map_tab[height - 1][i] == WALL
			|| map_tab[height - 1][i - 1] == WALL))
			top_wall = 1;
		else if (ft_strlen(map_tab[height - 1]) > i
			&& map_tab[height - 1][i + 1] == WALL)
			top_wall = 1;
		if (ft_strlen(map_tab[height + 1]) >= i
			&& (map_tab[height + 1][i] == WALL
			|| map_tab[height + 1][i - 1] == WALL))
			bottom_wall = 1;
		else if (ft_strlen(map_tab[height + 1]) > i
			&& map_tab[height + 1][i + 1] == WALL)
			bottom_wall = 1;
		if (top_wall == 1 && bottom_wall == 1)
			return (0);
		else
			i++;
	}
	return (print_error("The map is open"));
}

int	valid_border_line(char **map_tab, size_t max_height)
{
	size_t	i;

	i = 0;
	while (map_tab[0][i])
	{
		if (!(map_tab[0][i] == EMPTY || map_tab[0][i] == WALL))
			return (print_error("A border line is incorrect"));
		i++;
	}
	i = 0;
	while (map_tab[max_height][i])
	{
		if (!(map_tab[max_height][i] == EMPTY
			|| map_tab[max_height][i] == WALL))
			return (print_error("A border line is incorrect"));
		i++;
	}
	if (map_tab[max_height][i]
		&& !(map_tab[max_height][i] == EMPTY || map_tab[max_height][i] == WALL))
		return (print_error("A border line is incorrect"));
	return (0);
}
