/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:05:47 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/23 15:07:21 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_parse_map(t_map *map)
{
	int	i;

	i = 0;
	while (map && map->parse_map
		&& map->y
		&& i < map->y)
	{
		free(map->parse_map[i]);
		map->parse_map[i] = NULL;
		i++;
	}
	if (map && map->parse_map)
	{
		free(map->parse_map);
		map->parse_map = NULL;
	}
}

void	free_map_tab(t_map *map)
{
	int	i;

	i = 0;
	while (map && map->map_tab
		&& map->y
		&& i < map->y)
	{
		free(map->map_tab[i]);
		map->map_tab[i] = NULL;
		i++;
	}
	if (map && map->map_tab)
	{
		free(map->map_tab);
		map->map_tab = NULL;
	}
	if (map)
	{
		free(map);
		map = NULL;
	}
}
