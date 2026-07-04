/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:26:28 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/04 16:00:44 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

void	print_error(char *err_msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(err_msg, 2);
}

static void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
	{
		free(map->tab_map[i]);
		i++;
	}
	free(map->tab_map);
	free(map);
	map = NULL;
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
	if (ctx->map)
		free_map(ctx->map);
}
