/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:58:03 by jleray            #+#    #+#             */
/*   Updated: 2026/07/08 14:58:03 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	texture_data(t_ctx *ctx)
{
	int	i;
	int	w;
	int	h;

	i = 0;
	while (i < NB_TEXTURES)
	{
		ctx->wall_tex[i].img = mlx_xpm_file_to_image(ctx->mlx,
				ctx->tab_textures[i], &w, &h);
		ctx->wall_tex[i].addr = mlx_get_data_addr(ctx->wall_tex[i].img,
				&ctx->wall_tex[i].bits_per_pixel, &ctx->wall_tex[i].line_lenght,
				&ctx->wall_tex[i].endian);
		i++;
	}
	ctx->colors[0] = ft_atoi(ctx->tab_textures[FLOOR_COLOR]);
	ctx->colors[1] = ft_atoi(ctx->tab_textures[CEILING_COLOR]);
	ctx->tex.height = h;
	ctx->tex.witdh = w;
}
