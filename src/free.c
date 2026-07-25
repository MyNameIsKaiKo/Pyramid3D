/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:17:05 by jleray            #+#    #+#             */
/*   Updated: 2026/07/23 15:49:04 by ldepenne         ###   ########.fr       */
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

static void	sprite_free(t_ctx *ctx)
{
	int i;

	i = -1;
	while (++i < MAXLFRAME)
		if (ctx->sprites.lutin_t[i].img)
			mlx_destroy_image(ctx->mlx, ctx->sprites.lutin_t[i].img);
	i = -1;
	while (++i < MAXMFRAME)
		if (ctx->sprites.lutin_t[i].img)
			mlx_destroy_image(ctx->mlx, ctx->sprites.moine_t[i].img);
	i = -1;
	while (++i < MAXPFRAME)
		if (ctx->sprites.lutin_t[i].img)
			mlx_destroy_image(ctx->mlx, ctx->sprites.pirate_t[i].img);
}

static void	fandc_free(t_ctx *ctx)
{
	if (ctx->fandc_tex[0].img)
		mlx_destroy_image(ctx->mlx, ctx->fandc_tex[0].img);
	if (ctx->fandc_tex[1].img)
		mlx_destroy_image(ctx->mlx, ctx->fandc_tex[1].img);
}

void	tex_free(t_ctx *ctx)
{
	int	i;

	i = 0;
	if (!BONUS)
	{
		while (i < NB_TEXTURES)
		{
			if (ctx->wall_tex[i].img)
				mlx_destroy_image(ctx->mlx, ctx->wall_tex[i].img);
			i++;
		}
	}
	else if (BONUS)
	{
		while (i < NB_BONUS_TEX_WTHT_SPRITE)
		{
			if (ctx->wall_tex_bonus[i].img)
				mlx_destroy_image(ctx->mlx, ctx->wall_tex_bonus[i].img);
			i++;
		}
		sprite_free(ctx);
		fandc_free(ctx);
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
		free_bonus_struct(ctx);
	free_parse_map(ctx->map);
	free_map_tab(ctx->map);
}
