/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_data_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:22:24 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/31 15:16:04 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	get_bonus_color(t_ctx *ctx, int *w, int *h)
{
	ctx->fandc_tex[FLOOR_T].img = mlx_xpm_file_to_image(ctx->mlx,
			ctx->tab_tex_bonus[B_F_FLOOR_COLOR], w, h);
	ctx->fandc_tex[FLOOR_T].addr = mlx_get_data_addr
		(ctx->fandc_tex[FLOOR_T].img,
			&ctx->fandc_tex[FLOOR_T].bits_per_pixel,
			&ctx->fandc_tex[FLOOR_T].line_lenght,
			&ctx->fandc_tex[FLOOR_T].endian);
	ctx->fandc_tex[CEILING_T].img = mlx_xpm_file_to_image(ctx->mlx,
			ctx->tab_tex_bonus[B_C_CEILING_COLOR], w, h);
	ctx->fandc_tex[CEILING_T].addr = mlx_get_data_addr
		(ctx->fandc_tex[CEILING_T].img,
			&ctx->fandc_tex[CEILING_T].bits_per_pixel,
			&ctx->fandc_tex[CEILING_T].line_lenght,
			&ctx->fandc_tex[CEILING_T].endian);
}

void	texture_data_bonus(t_ctx *ctx, int *w, int *h)
{
	int	i;
	int	save;

	i = 0;
	while (i < NB_BONUS_TEX_WTHT_SPRITE)
	{
		ctx->wall_tex_bonus[i].img = mlx_xpm_file_to_image(ctx->mlx,
				ctx->tab_tex_bonus[i], w, h);
		ctx->wall_tex_bonus[i].addr = mlx_get_data_addr
			(ctx->wall_tex_bonus[i].img, &ctx->wall_tex_bonus[i].bits_per_pixel,
				&ctx->wall_tex_bonus[i].line_lenght,
				&ctx->wall_tex_bonus[i].endian);
		save = *w;
		if (i > 0 && save != *w && save != *h)
			printf("A wrong size in tex save : %d, w : %d, h : %d\n",
				save, *w, *h);
		i++;
	}
	get_bonus_color(ctx, w, h);
}
