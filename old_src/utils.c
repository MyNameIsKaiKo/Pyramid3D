/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:26:28 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/07 22:29:51 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

void	data_player(t_map *map, size_t height, size_t width)
{
	map->p_pos.x = width;
	map->p_pos.y = height;
	map->p_orient = map->tab_map[height][width];
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
	size_t	i;

	i = 0;
	while (map && i < map->height)
	{
		free(map->tab_map[i]);
		map->tab_map[i] = NULL;
		i++;
	}
	if (map && map->tab_map)
	{
		free(map->tab_map);
		map->tab_map = NULL;
	}
	if (map)
	{
		free(map);
		map = NULL;
	}
}

void	free_ctx(t_ctx *ctx)
{
	size_t	i;

	i = 0;
	while (i < NB_ALL_TEXTURES)
	{
		if (ctx->textures[i])
		{
			free(ctx->textures[i]);
			ctx->textures[i] = NULL;
		}
		++i;
	}
	free_map(ctx->map);
}
