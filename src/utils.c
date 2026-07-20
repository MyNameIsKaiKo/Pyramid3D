/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:26:28 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/20 21:41:54 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	data_player(t_map *map, size_t y, size_t x)
{
	map->starting_coord.x = x;
	map->starting_coord.y = y;
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

static void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map && map->y
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
	while (i < NB_ALL_TEXTURES)
	{
		if (ctx->tab_textures[i])
		{
			free(ctx->tab_textures[i]);
			ctx->tab_textures[i] = NULL;
		}
		++i;
	}
	free_map(ctx->map);
}
