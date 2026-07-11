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

static size_t	extract_color(char *color)
{
	size_t	e_color;
	size_t	r;
	size_t	g;
	size_t	b;
	char	**rgb;

	rgb = ft_split(color, ',');
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	e_color = (r << 16) | (g << 8) | b;
	return (e_color);
}

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
	ctx->colors[0] = extract_color(ctx->tab_textures[FLOOR_COLOR]);
	ctx->colors[1] = extract_color(ctx->tab_textures[CEILING_COLOR]);
	ctx->tex.height = h;
	ctx->tex.witdh = w;
}
