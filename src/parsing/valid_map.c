/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 18:48:57 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/21 10:16:07 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	rcolumn_isclose(char **parse_map,
	t_vec2 coor, int *twall, int *bwall)
{
	size_t	x;
	size_t	y;

	x = (size_t)coor.x;
	y = (size_t)coor.y;
	if (ft_strlen(parse_map[y - 1]) >= x
		&& (parse_map[y - 1][x] == WALL
		|| parse_map[y - 1][x - 1] == WALL))
		*twall = 1;
	else if (ft_strlen(parse_map[y - 1]) > x
		&& parse_map[y - 1][x + 1] == WALL)
		*twall = 1;
	if (ft_strlen(parse_map[y + 1]) >= x
		&& (parse_map[y + 1][x] == WALL
		|| parse_map[y + 1][x - 1] == WALL))
		*bwall = 1;
	else if (ft_strlen(parse_map[y + 1]) > x
		&& parse_map[y + 1][x + 1] == WALL)
		*bwall = 1;
	if (*twall == 1 && *bwall == 1)
		return (0);
	return (1);
}

int	valid_rcolumn_border(char **parse_map, size_t y)
{
	size_t	i;
	int		top_wall;
	int		bottom_wall;

	i = ft_strlen(parse_map[y]) - 1;
	top_wall = 0;
	bottom_wall = 0;
	while (parse_map[y][i] && parse_map[y][i] == EMPTY)
		i--;
	while (parse_map[y][i] && parse_map[y][i] == WALL)
	{
		if (rcolumn_isclose(parse_map, (t_vec2){i, y},
			&top_wall, &bottom_wall) == 0)
			return (0);
		else
			i--;
	}
	return (print_error("The map is open"));
}

static int	lcolumn_isclose(char **parse_map,
	t_vec2 coor, int *twall, int *bwall)
{
	size_t	x;
	size_t	y;

	x = (size_t)coor.x;
	y = (size_t)coor.y;
	if (parse_map[y - 1][x] == WALL
		|| (x > 0 && parse_map[y - 1][x - 1] == WALL))
		*twall = 1;
	else if (parse_map[y - 1][x + 1] == WALL)
		*twall = 1;
	if (parse_map[y + 1][x] == WALL
		|| (x > 0 && parse_map[y + 1][x - 1] == WALL))
		*bwall = 1;
	else if (parse_map[y + 1][x + 1] == WALL)
		*bwall = 1;
	if (*twall == 1 && *bwall == 1)
		return (0);
	return (1);
}

int	valid_lcolumn_border(char **parse_map, size_t y)
{
	size_t	i;
	int		top_wall;
	int		bottom_wall;

	i = 0;
	top_wall = 0;
	bottom_wall = 0;
	while (parse_map[y][i] && parse_map[y][i] == EMPTY)
		i++;
	while (parse_map[y][i] && parse_map[y][i] == WALL)
	{
		if (lcolumn_isclose(parse_map, (t_vec2){i, y},
			&top_wall, &bottom_wall) == 0)
			return (0);
		else
			i++;
	}
	return (print_error("The map is open"));
}

int	valid_border_line(char **parsemap_tab, size_t max_height)
{
	size_t	i;

	i = 0;
	while (parsemap_tab[0][i])
	{
		if (!(parsemap_tab[0][i] == EMPTY || parsemap_tab[0][i] == WALL))
			return (print_error("A border line is incorrect"));
		i++;
	}
	i = 0;
	while (parsemap_tab[max_height][i])
	{
		if (!(parsemap_tab[max_height][i] == EMPTY
			|| parsemap_tab[max_height][i] == WALL))
			return (print_error("A border line is incorrect"));
		i++;
	}
	if (parsemap_tab[max_height][i]
		&& !(parsemap_tab[max_height][i] == EMPTY
		|| parsemap_tab[max_height][i] == WALL))
		return (print_error("A border line is incorrect"));
	return (0);
}
