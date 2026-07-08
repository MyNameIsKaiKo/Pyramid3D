/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:26:28 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/08 14:07:23 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	data_player(t_map *map, size_t height, size_t width)
{
	map->starting_coord.x = width;
	map->starting_coord.y = height;
	map->p_orient = map->map_tab[height][width];
	map->nb_player++;
}

int	print_error(char *err_msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(err_msg, 2);
	return (1);
}

static void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map && i < map->height)
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
