/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_data_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:22:24 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/23 15:38:51 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	texture_data_bonus(t_ctx *ctx)
{
	int	i;
	int	w;
	int	h;

	i = 0;
	while (i < NB_BONUS_TEXTURES)
	{
		ctx->wall_tex_bonus[i].img = mlx_xpm_file_to_image(ctx->mlx,
				ctx->tab_tex_bonus[i], &w, &h);
		ctx->wall_tex_bonus[i].addr = mlx_get_data_addr
			(ctx->wall_tex_bonus[i].img, &ctx->wall_tex_bonus[i].bits_per_pixel,
				&ctx->wall_tex_bonus[i].line_lenght,
				&ctx->wall_tex_bonus[i].endian);
		i++;
	}
	get_bonus_color(ctx, &w, &h);
}
