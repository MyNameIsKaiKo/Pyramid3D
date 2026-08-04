/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_draw_tools_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:34:24 by jleray            #+#    #+#             */
/*   Updated: 2026/07/12 14:34:24 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	calc_floorxy(t_ctx *ctx)
{
	t_ray		*ray;
	t_texture	*tex;

	tex = &ctx->tex;
	ray = &ctx->player.ray;
	if (ray->side == 1)
	{
		tex->floor.x = ray->map_x + tex->wallx;
		if (ray->dir_y < 0)
			tex->floor.y = ray->map_y + 1.0;
		else
			tex->floor.y = ray->map_y;
	}
	else
	{
		tex->floor.y = ray->map_y + tex->wallx;
		if (ray->dir_x < 0)
			tex->floor.x = ray->map_x + 1.0;
		else
			tex->floor.x = ray->map_x;
	}
}

void	calc_floortex(t_ctx *ctx, int y)
{
	t_texture	*tex;
	double		current_dist;
	double		weight;

	tex = &ctx->tex;
	current_dist = (double)HEIGHT / (2 * y - (double)HEIGHT);
	weight = current_dist / ctx->player.ray.wall_dist;
	tex->floor.cfloor_x = weight * tex->floor.x + (1.0 - weight)
		* ctx->player.pos.x;
	tex->floor.cfloor_y = weight * tex->floor.y + (1.0 - weight)
		* ctx->player.pos.y;
	tex->floor.tex_x = (int)(tex->floor.cfloor_x * tex->witdh) % tex->witdh;
	tex->floor.tex_y = (int)(tex->floor.cfloor_y * tex->height) % tex->height;
	if (tex->floor.tex_x < 0)
		tex->floor.tex_x += tex->witdh;
	if (tex->floor.tex_y < 0)
		tex->floor.tex_y += tex->height;
}
