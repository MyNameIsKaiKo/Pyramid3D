/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:25:42 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/04 15:57:25 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

// static int	char_association(char c, t_map *map)
// {
// 	if ()
// }

static int	retrieve_map(char *line_read, t_map *map)
{
	int			i;
	t_tile_type	*new_line;

	i = 0;
	if (!map->tab_map)
		map->tab_map = malloc(sizeof(t_tile_type *));
	else
		map->tab_map = ft_realloc(map->tab_map, sizeof(t_tile_type *)
			* map->height, sizeof(t_tile_type *) * (map->height + 1));
	new_line = malloc(sizeof(t_tile_type) * ft_strlen(line_read));
	if (!map->tab_map || !new_line)
	{
		print_error("Malloc failed");
		return (1);
	}
	map->tab_map[map->height] = new_line;
	while (line_read[i])
	{
		// if (char_association(line_read[i], map) > 0)
		// 	return (1);
		i++;
	}
	return (0);
}

int	check_line_map(char *line_read, t_map *map)
{
	size_t	max_width;

	if (ft_strncmp(line_read, "\n", ft_strlen(line_read)) == 0)
	{
		if (map->height == 0)
			return (0);
		else
		{
			print_error("The map is open");
			return (1);
		}
	}
	max_width = ft_strlen(line_read);
	if (max_width > map->width)
		map->width = max_width;
	if (retrieve_map(line_read, map) > 0)
		return (1);
	map->height++;
	return (0);
}
