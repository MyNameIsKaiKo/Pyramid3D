/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:31:33 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/23 14:09:07 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/** @return 1 if is wall or 0 is not wall */
bool	iswall(t_tile_type c)
{
	return (c >= WALL && c <= WALL6);
}

int	close_map(char **tab, size_t y, size_t x)
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

void	data_challenger(t_map *map, size_t y, size_t x)
{
	map->challenger_pos.x = (double)x + 0.5;
	map->challenger_pos.y = (double)y + 0.5;
	map->nb_challenger++;
	map->parse_map[y][x] = FLOOR;
}

void	data_lutin(t_map *map, size_t y, size_t x)
{
	map->lutin_pos.x = (double)x + 0.5;
	map->lutin_pos.y = (double)y + 0.5;
	map->nb_lutin++;
	map->parse_map[y][x] = FLOOR;
}
