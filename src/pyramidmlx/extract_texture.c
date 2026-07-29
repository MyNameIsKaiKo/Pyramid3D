/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:58:03 by jleray            #+#    #+#             */
/*   Updated: 2026/07/28 17:10:56 by ldepenne         ###   ########.fr       */
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
	free(rgb[0]);
	free(rgb[1]);
	free(rgb[2]);
	free(rgb);
	return (e_color);
}

static void	get_color(t_ctx *ctx)
{
	ctx->colors[0] = extract_color(ctx->tab_textures[FLOOR_COLOR]);
	ctx->colors[1] = extract_color(ctx->tab_textures[CEILING_COLOR]);
}

void	texture_data(t_ctx *ctx)
{
	int	i;
	int	w;
	int	h;

	i = 0;
	w = 0;
	h = 0;
	if (!BONUS)
	{
		while (i < NB_TEXTURES)
		{
			ctx->wall_tex[i].img = mlx_xpm_file_to_image(ctx->mlx,
					ctx->tab_textures[i], &w, &h);
			ctx->wall_tex[i].addr = mlx_get_data_addr(ctx->wall_tex[i].img,
					&ctx->wall_tex[i].bits_per_pixel,
					&ctx->wall_tex[i].line_lenght, &ctx->wall_tex[i].endian);
			i++;
		}
		get_color(ctx);
	}
	else if (BONUS)
		texture_data_bonus(ctx, &w, &h);
	ctx->tex.height = h;
	ctx->tex.witdh = w;
}
