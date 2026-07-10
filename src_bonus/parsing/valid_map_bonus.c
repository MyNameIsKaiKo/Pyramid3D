/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 18:48:57 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/10 13:29:13 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static int	rcolumn_isclose(char **map_tab, t_vec2 coor, int *twall, int *bwall)
{
	size_t	x;
	size_t	height;

	x = (size_t)coor.x;
	height = (size_t)coor.y;
	if (ft_strlen(map_tab[height - 1]) >= x
		&& (map_tab[height - 1][x] == WALL
		|| map_tab[height - 1][x - 1] == WALL))
		*twall = 1;
	else if (ft_strlen(map_tab[height - 1]) > x
		&& map_tab[height - 1][x + 1] == WALL)
		*twall = 1;
	if (ft_strlen(map_tab[height + 1]) >= x
		&& (map_tab[height + 1][x] == WALL
		|| map_tab[height + 1][x - 1] == WALL))
		*bwall = 1;
	else if (ft_strlen(map_tab[height + 1]) > x
		&& map_tab[height + 1][x + 1] == WALL)
		*bwall = 1;
	if (*twall == 1 && *bwall == 1)
		return (0);
	return (1);
}

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
		if (rcolumn_isclose(map_tab, (t_vec2){i, height},
			&top_wall, &bottom_wall) == 0)
			return (0);
		else
			i--;
	}
	return (print_error("The map is open"));
}

static int	lcolumn_isclose(char **map_tab, t_vec2 coor, int *twall, int *bwall)
{
	size_t	x;
	size_t	height;

	x = (size_t)coor.x;
	height = (size_t)coor.y;
	if (map_tab[height - 1][x] == WALL
		|| (x > 0 && map_tab[height - 1][x - 1] == WALL))
		*twall = 1;
	else if (map_tab[height - 1][x + 1] == WALL)
		*twall = 1;
	if (map_tab[height + 1][x] == WALL
		|| (x > 0 && map_tab[height + 1][x - 1] == WALL))
		*bwall = 1;
	else if (map_tab[height + 1][x + 1] == WALL)
		*bwall = 1;
	if (*twall == 1 && *bwall == 1)
		return (0);
	return (1);
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
		if (lcolumn_isclose(map_tab, (t_vec2){i, height},
			&top_wall, &bottom_wall) == 0)
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
