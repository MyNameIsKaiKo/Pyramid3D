/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 19:30:58 by ldepenne          #+#    #+#             */
/*   Updated: 2026/08/05 11:59:11 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	around_floor(char **tab, size_t y, size_t x)
{
	if (ft_strlen(tab[y + 1]) < ft_strcharlen(tab[y], tab[y][x]))
		return (print_error("The map is open"));
	if (x == 0 && !(tab[y][x] >= NO_WALL && tab[y][x] <= WE_WALL))
		return (print_error("The map is open"));
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
		if (around_floor (tab, y, x) > 0)
			return (1);
		data_player(map, y, x);
		return (0);
	}
	print_error("A char in map is incorrect");
	return (1);
}
