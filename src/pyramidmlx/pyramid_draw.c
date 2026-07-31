/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:17:52 by jleray            #+#    #+#             */
/*   Updated: 2026/07/31 11:03:16 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	setup_ray_for_col(t_ctx *ctx, int x)
{
	t_ray	*ray;

	ray = &ctx->player.ray;
	ray->camera_x = 2.0 * x / (double)WIDTH - 1.0;
	ray->dir_x = ctx->player.dir.x + ctx->player.plane.x * ray->camera_x;
	ray->dir_y = ctx->player.dir.y + ctx->player.plane.y * ray->camera_x;
	ray->map_x = (int)ctx->player.pos.x;
	ray->map_y = (int)ctx->player.pos.y;
	calc_deltadist(ray);
	calc_sidedist(ray, ctx);
}

static void	exec_dda(t_map *map, t_ctx *ctx)
{
	t_ray	*ray;

	ray = &ctx->player.ray;
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_x < 0 || ray->map_x >= map->x || ray->map_y < 0
			|| ray->map_y >= map->y)
			break ;
		if (map->map_tab[ray->map_y][ray->map_x] != '0'
			&& map->map_tab[ray->map_y][ray->map_x] != 'o')
			ray->hit = 1;
	}
}

static void	calc_wall(t_ctx *ctx)
{
	t_ray	*ray;

	ray = &ctx->player.ray;
	if (ray->side == 0)
		ray->wall_dist = ray->sidedist_x - ray->deltadist_x;
	else if (ray->side == 1)
		ray->wall_dist = ray->sidedist_y - ray->deltadist_y;
}

static void	draw_img(t_ctx *ctx, int x)
{
	t_ray	*ray;
	int		y;
	int		color;

	y = -1;
	ray = &ctx->player.ray;
	setup_draw_img(ctx);
	get_tex_index(ctx);
	while (++y < HEIGHT)
	{
		if (y < ray->draw_start)
			my_mlx_pixel_put(ctx, x, y, ctx->colors[0]);
		else if (y > ray->draw_end)
			my_mlx_pixel_put(ctx, x, y, ctx->colors[1]);
		else
		{
			calc_tex_y(ctx);
			ctx->tex.start += ctx->tex.step;
			color = get_texture_pixel(&ctx->wall_tex[ctx->tex.index],
					ctx->tex.x, ctx->tex.y);
			my_mlx_pixel_put(ctx, x, y, color);
		}
	}
}

int	draw_frame(t_ctx *ctx)
{
	int	x;

	x = 0;
	protect_player(ctx);
	if (player_moved(&ctx->player))
		apply_movement(ctx);
	early_door_check(ctx);
	while (x < WIDTH)
	{
		setup_ray_for_col(ctx, x);
		exec_dda(ctx->map, ctx);
		calc_wall(ctx);
		if (BONUS)
			draw_img_bonus(ctx, x);
		else
			draw_img(ctx, x);
		ctx->player.ray.hit = 0;
		x++;
	}
	if (BONUS)
		draw_bonus(ctx);
	draw_crossair(ctx);
	mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img.img, 0, 0);
	return (0);
}
