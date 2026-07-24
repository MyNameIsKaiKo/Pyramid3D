/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_draw_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:31:49 by jleray            #+#    #+#             */
/*   Updated: 2026/07/23 15:19:27 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_floor(t_ctx *ctx, int x, int y)
{
	int	color;

	calc_floortex(ctx, y);
	color = get_texture_pixel(&ctx->fandc_tex[0],
			ctx->tex.floor.tex_x,
			ctx->tex.floor.tex_y);
	my_mlx_pixel_put(ctx, x, y, color);
}

static void	draw_ceiling(t_ctx *ctx, int x, int y)
{
	int	color;

	calc_floortex(ctx, HEIGHT - y - 1);
	color = get_texture_pixel(&ctx->fandc_tex[1],
			ctx->tex.floor.tex_x,
			ctx->tex.floor.tex_y);
	my_mlx_pixel_put(ctx, x, y, color);
}

static void	draw_walls(t_ctx *ctx, int x, int y)
{
	int	color;

	calc_tex_y(ctx);
	ctx->tex.start += ctx->tex.step;
	if (!BONUS)
		color = get_texture_pixel(&ctx->wall_tex[ctx->tex.index], ctx->tex.x,
				ctx->tex.y);
	else if (BONUS)
		color = get_texture_pixel(&ctx->wall_tex_bonus[ctx->tex.index],
				ctx->tex.x, ctx->tex.y);
	my_mlx_pixel_put(ctx, x, y, color);
}

void	draw_img_bonus(t_ctx *ctx, int x)
{
	t_ray	*ray;
	int		y;

	y = -1;
	ray = &ctx->player.ray;
	setup_draw_img(ctx);
	ctx->sprites.buffer[x] = ctx->player.ray.wall_dist;
	get_tex_index(ctx);
	calc_floorxy(ctx);
	while (++y < HEIGHT)
	{
		if (y < ray->draw_start)
			draw_ceiling(ctx, x, y);
		else if (y > ray->draw_end)
			draw_floor(ctx, x, y);
		else
			draw_walls(ctx, x, y);
	}
}
