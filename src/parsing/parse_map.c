/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:25:42 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/31 12:00:35 by ldepenne         ###   ########.fr       */
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

/** @brief look around the floor, return error if map is open */
int	isopen_map(char **tab, size_t y, size_t x)
{
	char	top_case;
	char	left_case;
	char	right_case;
	char	bottom_case;

	top_case = tab[y - 1][x];
	left_case = tab[y][x - 1];
	right_case = tab[y][x + 1];
	bottom_case = tab[y + 1][x];
	if ((top_case != WALL && top_case != FLOOR && !isplayer(top_case))
		|| (left_case != WALL && left_case != FLOOR && !isplayer(left_case))
		|| (right_case != WALL && right_case != FLOOR && !isplayer(right_case))
		|| (bottom_case != WALL && bottom_case != FLOOR
			&& !isplayer(bottom_case)))
		return (print_error("Map is open or have a char invalid"));
	return (0);
}

int	parse_map(t_map *map)
{
	int	y;
	int	x;

	if (!map->parse_map)
		return (print_error("Don't have map"));
	if (border_line_check(map->parse_map, 0) > 0)
		return (1);
	if (border_line_check(map->parse_map, map->y - 1) > 0)
		return (1);
	y = 1;
	while (y < map->y - 1)
	{
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

static int	recover_map(char *line_read, t_map *map)
{
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
		{
			if (BONUS && map->y - 1 >= 0
				&& first_line(map->parse_map, map->y - 1))
				return (print_error("The map is open"));
			else if (!BONUS && map->y - 1 >= 0
				&& border_line_check(map->parse_map, map->y - 1))
				return (print_error("The map is open"));
		}
	}
	max_width = ft_strlen(line_read);
	if (max_width > map->x)
		map->x = max_width;
	if (recover_map(line_read, map) > 0)
		return (1);
	map->y++;
	return (0);
}
