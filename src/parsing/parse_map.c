/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:25:42 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/08 10:55:32 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	space_in_map(char **tab, size_t height, size_t width)
{
	if (!tab[height][width - 1] || !tab[height][width + 1]
		|| !tab[height - 1][width] || !tab[height + 1][width])
		return (print_error("Map is open"));
	if (tab[height][width - 1] == EMPTY || tab[height][width + 1] == EMPTY
		|| tab[height - 1][width] == EMPTY
		|| tab[height + 1][width] == EMPTY)
		return (print_error("There is a space in map"));
	return (0);
}

static int	check_char(char **tab, size_t height, size_t width, t_map *map)
{
	char	c;

	c = tab[height][width];
	if (c == WALL || c == EMPTY)
		return (0);
	if (c == FLOOR)
	{
		if (space_in_map(tab, height, width) > 0)
			return (1);
		return (0);
	}
	if (c == N_PLAYER || c == E_PLAYER || c == S_PLAYER || c == W_PLAYER)
	{
		data_player(map, height, width);
		return (0);
	}
	print_error("A char in map is incorrect");
	return (1);
}

int	parse_map(t_map *map)
{
	int	height;
	int	width;

	if (valid_border_line(map->map_tab, map->height - 1) > 0)
		return (1);
	height = 1;
	while (height < map->height - 1)
	{
		if (valid_lcolumn_border(map->map_tab, height) > 0)
			return (1);
		if (valid_rcolumn_border(map->map_tab, height) > 0)
			return (1);
		width = 0;
		while (map->map_tab[height][width] && width < map->width)
		{
			if (check_char(map->map_tab, height, width, map) > 0)
				return (1);
			if (map->nb_player > 1)
				return (print_error("There is too many players"));
			width++;
		}
		height++;
	}
	return (0);
}

static int	retrieve_map(char *line_read, t_map *map)
{
	int	i;

	i = 0;
	if (!map->map_tab)
		map->map_tab = malloc(sizeof(char *) + 1);
	else
		map->map_tab = ft_realloc(map->map_tab, sizeof(char *)
				* map->height, sizeof(char *) * ((map->height + 1) + 1));
	if (!map->map_tab)
		return (print_error("Malloc failed"));
	if (line_read[ft_strlen(line_read) - 1] == '\n')
		line_read[ft_strlen(line_read) - 1] = '\0';
	map->map_tab[map->height] = ft_strndup(line_read, ft_strlen(line_read));
	if (!map->map_tab[map->height])
		return (print_error("Malloc failed"));
	return (0);
}

int	check_line_map(char *line_read, t_map *map)
{
	int	max_width;

	if (ft_strncmp(line_read, "\n", ft_strlen(line_read)) == 0)
	{
		if (map->height == 0)
			return (0);
		else
			return (print_error("The map is open"));
	}
	max_width = ft_strlen(line_read);
	if (max_width > map->width)
		map->width = max_width;
	if (retrieve_map(line_read, map) > 0)
		return (1);
	map->height++;
	return (0);
}
