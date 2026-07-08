/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:26:37 by jleray            #+#    #+#             */
/*   Updated: 2026/07/08 10:25:44 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	f_init(t_ctx *ctx)
{
	if (!ctx->img.addr)
	{
		mlx_destroy_image(ctx->mlx, ctx->img.img);
		mlx_destroy_window(ctx->mlx, ctx->win);
		free(ctx->mlx);
	}
	else if (!ctx->img.img)
	{
		mlx_destroy_window(ctx->mlx, ctx->win);
		free(ctx->mlx);
	}
	else if (!ctx->win)
		free(ctx->mlx);
	ft_putstr_fd("Malloc Error\n", 1);
}

void	map_free(t_map *map)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		free(map->map_tab[i]);
		i++;
	}
	free(map->map_tab);
}

void	tex_free(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(ctx->mlx, ctx->wall_tex[i].img);
		i++;
	}
}
