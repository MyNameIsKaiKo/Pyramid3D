/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:17:05 by jleray            #+#    #+#             */
/*   Updated: 2026/07/23 14:26:07 by ldepenne         ###   ########.fr       */
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

void	tex_free(t_ctx *ctx)
{
	int	i;

	i = 0;
	if (!BONUS)
	{
		while (i < NB_TEXTURES)
		{
			mlx_destroy_image(ctx->mlx, ctx->wall_tex[i].img);
			i++;
		}
	}
	if (BONUS)
	{
		while (i < NB_BONUS_TEXTURES)
		{
			mlx_destroy_image(ctx->mlx, ctx->wall_tex_bonus[i].img);
			i++;
		}
	}
}
