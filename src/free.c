/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:17:05 by jleray            #+#    #+#             */
/*   Updated: 2026/07/23 15:13:58 by ldepenne         ###   ########.fr       */
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
		mlx_destroy_image(ctx->mlx, ctx->fandc_tex[0].img);
		mlx_destroy_image(ctx->mlx, ctx->fandc_tex[1].img);
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
		free_bonus_strutc(ctx);
	free_parse_map(ctx->map);
	free_map_tab(ctx->map);
}
