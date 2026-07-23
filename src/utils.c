/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:26:28 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/23 14:54:26 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	data_player(t_map *map, size_t y, size_t x)
{
	map->starting_coord.x = (double)x + 0.5;
	map->starting_coord.y = (double)y + 0.5;
	map->p_orient = map->parse_map[y][x];
	map->nb_player++;
	map->parse_map[y][x] = FLOOR;
}

int	print_error(const char *err_msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(err_msg, 2);
	return (1);
}

/** @brief return number of char before char c, c include*/
size_t	ft_strcharlen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

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

static void	free_map_tab(t_map *map)
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

void	free_ctx(t_ctx *ctx)
{
	int	i;

	i = 0;
	if (!BONUS)
	{
		while (i < NB_ALL_TEXTURES)
		{
			if (ctx->tab_textures[i])
			{
				free(ctx->tab_textures[i]);
				ctx->tab_textures[i] = NULL;
			}
			++i;
		}
	}
	if (BONUS)
	{
		while (i < NB_BONUS_TEXTURES)
		{
			if (ctx->tab_tex_bonus[i])
			{
				free(ctx->tab_tex_bonus[i]);
				ctx->tab_tex_bonus[i] = NULL;
			}
			++i;
		}
	}
	free_parse_map(ctx->map);
	free_map_tab(ctx->map);
}
