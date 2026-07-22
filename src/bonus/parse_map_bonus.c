/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 11:36:39 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/22 09:51:52 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	fst_lst_line(char **tab, size_t max_y)
{
	size_t	x;
	char	*fst_line;
	char	*lst_line;

	x = 0;
	fst_line = tab[0];
	lst_line = tab[max_y - 1];
	while (fst_line[x])
	{
		if (!(iswall(fst_line[x]) || fst_line[x] == EMPTY))
			return (print_error("A border line is incorrect"));
		x++;
	}
	x = 0;
	while (lst_line[x])
	{
		if (!(iswall(fst_line[x]) || fst_line[x] == EMPTY))
			return (print_error("A border line is incorrect"));
		x++;
	}
	return (0);
}

static int	close_map(char **tab, size_t y, size_t x)
{
	char	top_case;
	char	left_case;
	char	right_case;
	char	bottom_case;

	top_case = tab[y - 1][x];
	left_case = tab[y][x - 1];
	right_case = tab[y][x + 1];
	bottom_case = tab[y + 1][x];
	if (!iswall(top_case) && top_case != FLOOR)
		return (1);
	return (0);
}

static int	check_floor(char **tab, size_t y, size_t x)
{
	if (space_in_map(tab, y, x) > 0
		|| close_map(tab, y, x) > 0)
		return (1);
	return (0);
}

static int	check_charbonus(char **tab, size_t y, size_t x, t_map *map)
{
	char	c;

	c = tab[y][x];
	if (c == WALL || c == EMPTY)
		return (0);
	if (c == WALL || c == WALL2 || c == WALL3 || c == WALL4
		|| c == WALL5 || c == WALL6)
		return (0);
	if (c == FLOOR)
	{
		if (check_floor(tab, y, x) > 0)
			return (1);
		return (0);
	}
	if (c == N_PLAYER || c == E_PLAYER || c == S_PLAYER || c == W_PLAYER)
	{
		data_player(map, y, x);
		return (0);
	}
	print_error("A char in map is incorrect");
	return (1);
}

int	parse_map_bonus(t_map *map)
{
	int	y;
	int	x;

	if (fst_lst_line(map->parse_map, map->y) > 0)
		return (1);
	y = 1;
	while (y < map->y - 1)
	{
		x = 0;
		while (map->parse_map[y][x] && x < map->x)
		{
			if (check_charbonus(map->parse_map, y, x, map) > 0)
				return (1);
			if (map->nb_player > 1)
				return (print_error("There is too many players"));
			x++;
		}
		y++;
	}
	return (0);
}
