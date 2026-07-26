/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 19:30:58 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/26 21:20:42 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	around_floor(char **tab, size_t y, size_t x)
{
	if (space_in_map(tab, y, x) > 0
		|| isopen_map(tab, y, x) > 0)
		return (1);
	return (0);
}

int	check_char(char **tab, size_t y, size_t x, t_map *map)
{
	char	c;

	c = tab[y][x];
	if (c == WALL || c == EMPTY)
		return (0);
	if (c == FLOOR)
	{
		if (around_floor (tab, y, x) > 0)
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
