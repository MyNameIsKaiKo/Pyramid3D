/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:32:25 by jleray            #+#    #+#             */
/*   Updated: 2026/07/08 14:32:25 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	calc_wallx(t_ctx *ctx)
{
	t_player	*player;
	t_ray		*ray;

	player = &ctx->player;
	ray = &player->ray;
	if (ray->side == 0)
		ctx->tex.wallx = player->pos.y + ray->wall_dist * ray->dir_y;
	if (ray->side == 1)
		ctx->tex.wallx = player->pos.x + ray->wall_dist * ray->dir_x;
	ctx->tex.wallx = ctx->tex.wallx - (int)ctx->tex.wallx;
}

void	calc_tex_x(t_ctx *ctx)
{
	t_player	*player;
	t_ray		*ray;
	t_texture	*tex;

	player = &ctx->player;
	ray = &player->ray;
	tex = &ctx->tex;
	tex->x = (int)(tex->wallx * tex->witdh);
	if (tex->x < 0)
		tex->x = 0;
	if (tex->x >= tex->witdh)
		tex->x = tex->witdh - 1;
	if (ray->side == 0 && ray->dir_x > 0)
		tex->x = tex->witdh - tex->x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		tex->x = tex->witdh - tex->x - 1;
}

void	calc_tex_step(t_ctx *ctx)
{
	t_ray		*ray;
	t_texture	*tex;

	ray = &ctx->player.ray;
	tex = &ctx->tex;
	tex->step = (1.0 * tex->height) / ray->line_height;
}

void	calc_tex_start(t_ctx *ctx)
{
	t_ray		*ray;
	t_texture	*tex;

	ray = &ctx->player.ray;
	tex = &ctx->tex;
	tex->start = (ray->draw_start - (HEIGHT / 2) + (ray->line_height / 2))
		* tex->step;
}

int	get_texture_pixel(t_img *tex_img, int x, int y)
{
	char	*dst;

	dst = tex_img->addr + (y * tex_img->line_lenght + x
			* (tex_img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
