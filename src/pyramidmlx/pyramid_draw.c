/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:17:52 by jleray            #+#    #+#             */
/*   Updated: 2026/07/08 14:17:52 by jleray           ###   ########.fr       */
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
		if (ray->map_x < 0 || ray->map_x >= map->width || ray->map_y < 0
			|| ray->map_y >= map->height)
			break ;
		if (map->map_tab[ray->map_y][ray->map_x] != '0')
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

// void	draw_img(t_map *map, int x)
// {
// t_ray	*ray;
// int		y;
//
// y = -1;
// ray = &map->player.ray;
// calc_drawing_value(ray);
// while (++y < HEIGHT)
// {
// if (y <= ray->draw_end && y >= ray->draw_start)
// {
// if (ray->side == 1)
// my_mlx_pixel_put(map, x, y, 0x00000000);
// else if (ray->side == 0)
// my_mlx_pixel_put(map, x, y, 0x00FFFFFF);
// }
// if (y < ray->draw_start)
// my_mlx_pixel_put(map, x, y, 0x00F02DC3);
// if (y > ray->draw_end)
// my_mlx_pixel_put(map, x, y, 0x00F02D00);
// }
// }

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
	if (player_moved(&ctx->player))
		apply_movement(ctx);
	while (x < WIDTH)
	{
		setup_ray_for_col(ctx, x);
		exec_dda(ctx->map, ctx);
		calc_wall(ctx);
		draw_img(ctx, x);
		ctx->player.ray.hit = 0;
		x++;
	}
	mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img.img, 0, 0);
	return (0);
}
