/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:25:42 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/06 20:05:02 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

static void	data_player(t_map *map, size_t height, size_t width)
{
	map->p_pos.x = width;
	map->p_pos.y = height;
	map->p_orient = map->tab_map[height][width];
	map->nb_player++;
}

static int	check_char(char ** tab, size_t height, size_t width, t_map *map)
{
	char	c;

	c = tab[height][width];
	if (c == WALL || c == EMPTY)
		return (0);
	if (c == FLOOR)
	{
		if (tab[height][width - 1] == EMPTY || tab[height][width + 1] == EMPTY
			|| tab[height - 1][width] == EMPTY || tab[height + 1][width] == EMPTY)
			return (print_error("There is a space in map"));
		return (0);
	}
	if (c == N_PLAYER || c == E_PLAYER || c == S_PLAYER || c == W_PLAYER)
	{
		data_player(map, height, width);
		return (0);
	}
	print_error("A char in map is incorrect");
	if (valid_lcolumn_border(map->tab_map, height) == 0
		&& valid_rcolumn_border(map->tab_map, height) == 0 )
		return (0);
	return (1);
}

int	parse_map(t_map *map)
{
	size_t	height;
	size_t	width;

	if (valid_border_line(map->tab_map, map->height - 1) > 0)
		return (1);
	height = 1;
	while (height < map->height)
	{
		width = 0;
		while (map->tab_map[height][width] && width < map->max_width)
		{
			if (check_char(map->tab_map, height, width, map) > 0)
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
	if (!map->tab_map)
		map->tab_map = malloc(sizeof(char *));
	else
		map->tab_map = ft_realloc(map->tab_map, sizeof(char *)
			* map->height, sizeof(char *) * (map->height + 1));
	if (!map->tab_map)
		return (print_error("Malloc failed"));
	line_read[ft_strlen(line_read) - 1] ='\0';
	map->tab_map[map->height] = ft_strndup(line_read, ft_strlen(line_read));
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
			return (print_error("The map is open"));
	}
	max_width = ft_strlen(line_read);
	if (max_width > map->max_width)
		map->max_width = max_width;
	if (retrieve_map(line_read, map) > 0)
		return (1);
	map->height++;
	return (0);
}
