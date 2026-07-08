/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_scd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 02:43:16 by jleray            #+#    #+#             */
/*   Updated: 2026/07/08 11:09:51 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	calc_tex_y(t_ctx *ctx)
{
	t_texture	*tex;

	tex = &ctx->tex;
	tex->y = (int)tex->start % tex->height;
	if (tex->y < 0)
		tex->y = 0;
	if (tex->y >= tex->height)
		tex->y = tex->height - 1;
}

void	get_tex_index(t_ctx *ctx)
{
	t_ray	*ray;

	ray = &ctx->player.ray;
	if (ray->side == 0 && ray->dir_x < 0)
		ctx->tex.index = 0;
	if (ray->side == 1 && ray->dir_y > 0)
		ctx->tex.index = 1;
	if (ray->side == 0 && ray->dir_x > 0)
		ctx->tex.index = 2;
	if (ray->side == 1 && ray->dir_y < 0)
		ctx->tex.index = 3;
}
