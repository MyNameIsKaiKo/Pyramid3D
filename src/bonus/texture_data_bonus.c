/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_data_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:22:24 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/25 16:18:57 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	get_bonus_color(t_ctx *ctx, int *w, int *h)
{
	int	floor;
	int	ceil;

	floor = 0;
	ceil = 1;
	ctx->fandc_tex[floor].img = mlx_xpm_file_to_image(ctx->mlx,
			ctx->tab_tex_bonus[B_F_FLOOR_COLOR], w, h);
	ctx->fandc_tex[floor].addr = mlx_get_data_addr(ctx->fandc_tex[floor].img,
			&ctx->fandc_tex[floor].bits_per_pixel,
			&ctx->fandc_tex[floor].line_lenght, &ctx->fandc_tex[floor].endian);
	ctx->fandc_tex[ceil].img = mlx_xpm_file_to_image(ctx->mlx,
			ctx->tab_tex_bonus[B_C_CEILING_COLOR], w, h);
	ctx->fandc_tex[ceil].addr = mlx_get_data_addr(ctx->fandc_tex[ceil].img,
			&ctx->fandc_tex[ceil].bits_per_pixel,
			&ctx->fandc_tex[ceil].line_lenght,
			&ctx->fandc_tex[ceil].endian);
}

void	texture_data_bonus(t_ctx *ctx, int *w, int *h)
{
	int	i;

	i = 0;
	while (i < NB_BONUS_TEX_WTHT_SPRITE)
	{
		ctx->wall_tex_bonus[i].img = mlx_xpm_file_to_image(ctx->mlx,
				ctx->tab_tex_bonus[i], w, h);
		ctx->wall_tex_bonus[i].addr = mlx_get_data_addr
			(ctx->wall_tex_bonus[i].img, &ctx->wall_tex_bonus[i].bits_per_pixel,
				&ctx->wall_tex_bonus[i].line_lenght,
				&ctx->wall_tex_bonus[i].endian);
		i++;
	}
	get_bonus_color(ctx, w, h);
}
