/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 16:00:15 by jleray            #+#    #+#             */
/*   Updated: 2026/07/29 10:44:45 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	load_wp_frame(t_ctx *ctx, char *path, t_img *tex)
{
	int	w;
	int	h;

	tex->img = mlx_xpm_file_to_image(ctx->mlx, path, &w, &h);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_lenght, &tex->endian);
	ctx->player.weapon_h = h;
	ctx->player.weapon_w = w;
}

static int	get_weapon_frame(t_player *player)
{
	if (player->wstate == W_HOLD)
		return (1);
	if (player->wstate == W_FIRE)
	{
		player->timer++;
		if (player->timer > 10)
		{
			player->timer = 0;
			player->wstate = W_IDLE;
			return (0);
		}
		return (2);
	}
	return (0);
}

void	draw_gun(t_ctx *ctx)
{
	t_vec2	start;
	int		x;
	int		y;
	int		color;
	int		f;

	f = get_weapon_frame(&ctx->player);
	start.x = (WIDTH / 2.0) - ((ctx->player.weapon_w * 3) / 2.0) + 160;
	start.y = HEIGHT - (ctx->player.weapon_h * 3);
	x = -1;
	while (++x < ctx->player.weapon_w * 3)
	{
		y = -1;
		while (++y < ctx->player.weapon_h * 3)
		{
			color = get_texture_pixel(&ctx->player.weapon_t[f], x / 3, y / 3);
			if (color != ERASE_C)
				my_mlx_pixel_put(ctx, start.x + x, start.y + y, color);
		}
	}
}

void	shoot_weapon(t_ctx *ctx)
{
	int		i;
	double	hit;
	double	dot;
	t_vec2	delta;

	i = -1;
	while (++i < ctx->sprites.count)
	{
		if (ctx->sprites.arr[i].type == T_MOINE)
		{
			delta = get_delta(ctx, i);
			dot = (ctx->player.dir.x * delta.x) + (ctx->player.dir.y * delta.y);
			hit = fabs(ctx->player.dir.x
					* delta.y - ctx->player.dir.y * delta.x);
			if (dot > 0 && hit < 0.5 && ctx->sprites.arr[i].dist < 50.0)
				ctx->sprites.arr[i].type = T_NULL;
		}
	}
	check_alive_moine(ctx);
}
