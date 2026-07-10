/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_draw_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:30:19 by jleray            #+#    #+#             */
/*   Updated: 2026/07/10 13:29:13 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	calc_deltadist(t_ray *ray)
{
	if (ray->dir_x == 0)
		ray->deltadist_x = 1e30;
	else
		ray->deltadist_x = fabs(1.0 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->deltadist_y = 1e30;
	else
		ray->deltadist_y = fabs(1.0 / ray->dir_y);
}

void	calc_sidedist(t_ray *ray, t_ctx *ctx)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (ctx->player.pos.x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - ctx->player.pos.x)
			* ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (ctx->player.pos.y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - ctx->player.pos.y)
			* ray->deltadist_y;
	}
}

void	calc_drawing_value(t_ray *ray)
{
	if (ray->wall_dist != 0)
		ray->line_height = HEIGHT / ray->wall_dist;
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

void	setup_draw_img(t_ctx *ctx)
{
	calc_drawing_value(&ctx->player.ray);
	calc_wallx(ctx);
	calc_tex_x(ctx);
	calc_tex_step(ctx);
	calc_tex_start(ctx);
}
