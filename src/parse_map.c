/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 19:37:43 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/02 14:57:34 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

	// FLOOR,
	// WALL,
	// EMPTY,
	// PLAYER

static int	distribution(char *line, t_map *map)
{
	int		i;
	char	c;

	i = 0;
	printf("in distribution:\n");
	while (line[i])
	{
		c = line[i];
		printf("c: '%c'\n", c);
		if (c == ' ')
		{
			printf("space\n");
			map->tab_map[map->height][i] = EMPTY;
		}
		else if (c == '0')
		{
			printf("0\n");
			map->tab_map[map->height][i] = FLOOR;
		}
		else if (c == '1')
		{
			printf("1\n");
			map->tab_map[map->height][i] = WALL;
		}
		else if ((c == 'N' || c == 'S' || c == 'W' || c == 'E') && map->n_player == false)
		{
			printf("%c\n", c);
			map->tab_map[map->height][i] = WALL;
			map->n_player = true;
		}
		else
		{
			printf("return\n");
			return (1);
		}
	}
	return (0);
}

int	parse_map(char *line_read, t_map *map)
{
	size_t	current_size;
	size_t	new_size;

	current_size = map->height * sizeof(t_tile_type *);
	new_size = (map->height + 1) * sizeof(t_tile_type *);
	if (map->height < 1)
		map->tab_map = malloc(sizeof(t_tile_type *) * ft_strlen(line_read));
	else
		map->tab_map = ft_realloc(map->tab_map, current_size, new_size);
	if (!map->tab_map)
	{
		print_error("ft_realloc failed");
		return (1);
	}
	if (distribution(line_read, map) > 0)
		return (1);
	return (0);
}
