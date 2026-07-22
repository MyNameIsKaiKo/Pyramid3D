/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:25:42 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/21 17:13:50 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	space_in_map(char **tab, size_t y, size_t x)
{
	if (!tab[y][x - 1] || !tab[y][x + 1]
		|| !tab[y - 1][x] || !tab[y + 1][x])
		return (print_error("Map is open"));
	if (tab[y][x - 1] == EMPTY || tab[y][x + 1] == EMPTY
		|| tab[y - 1][x] == EMPTY
		|| tab[y + 1][x] == EMPTY)
		return (print_error("There is a space in map"));
	return (0);
}

static int	check_char(char **tab, size_t y, size_t x, t_map *map)
{
	char	c;

	c = tab[y][x];
	if (c == WALL || c == EMPTY)
		return (0);
	if (c == FLOOR)
	{
		if (space_in_map(tab, y, x) > 0)
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

int	parse_map(t_map *map)
{
	int	y;
	int	x;

	if (valid_border_line(map->parse_map, map->y - 1) > 0)
		return (1);
	y = 1;
	while (y < map->y - 1)
	{
		if (valid_lcolumn_border(map->parse_map, y) > 0)
			return (1);
		if (valid_rcolumn_border(map->parse_map, y) > 0)
			return (1);
		x = 0;
		while (map->parse_map[y][x] && x < map->x)
		{
			if (check_char(map->parse_map, y, x, map) > 0)
				return (1);
			if (map->nb_player > 1)
				return (print_error("There is too many players"));
			x++;
		}
		y++;
	}
	return (0);
}

static int	retrieve_map(char *line_read, t_map *map)
{
	int	i;

	i = 0;
	if (!map->parse_map)
		map->parse_map = malloc(sizeof(char *) + 1);
	else
		map->parse_map = ft_realloc(map->parse_map, sizeof(char *)
				* map->y, sizeof(char *) * ((map->y + 1) + 1));
	if (!map->parse_map)
		return (print_error("Malloc failed"));
	if (line_read[ft_strlen(line_read) - 1] == '\n')
		line_read[ft_strlen(line_read) - 1] = '\0';
	map->parse_map[map->y] = ft_strndup(line_read, ft_strlen(line_read));
	if (!map->parse_map[map->y])
		return (print_error("Malloc failed"));
	return (0);
}

int	check_line_map(char *line_read, t_map *map)
{
	int	max_width;

	if (ft_strncmp(line_read, "\n", ft_strlen(line_read)) == 0)
	{
		if (map->y == 0)
			return (0);
		else
			return (print_error("The map is open"));
	}
	max_width = ft_strlen(line_read);
	if (max_width > map->x)
		map->x = max_width;
	if (retrieve_map(line_read, map) > 0)
		return (1);
	map->y++;
	return (0);
}
