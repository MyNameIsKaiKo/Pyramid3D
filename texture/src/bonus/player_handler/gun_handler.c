/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 16:00:15 by jleray            #+#    #+#             */
/*   Updated: 2026/07/31 15:14:17 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	load_wp_frame(t_ctx *ctx, char *path, t_img *tex)
{
	int	w;
	int	h;

	tex->img = mlx_xpm_file_to_image(ctx->mlx, path, &w, &h);
	if (!tex->img)
		img_xpm_error(ctx);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_lenght, &tex->endian);
	ctx->player.weapon_h = h;
	ctx->player.weapon_w = w;
	tex->width = w;
	tex->height = h;
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

static void	safe_draw(t_ctx *ctx, t_vec2 start, int color, t_vec2 coord)
{
	int	draw_x;
	int	draw_y;

	draw_x = start.x + coord.x;
	draw_y = start.y + coord.y;
	if (draw_x >= 0 && draw_x < WIDTH && draw_y >= 0 && draw_y < HEIGHT)
	{
		my_mlx_pixel_put(ctx, draw_x, draw_y, color);
	}
}

void	draw_gun(t_ctx *ctx)
{
	t_vec2	start;
	t_vec2	coord;
	int		color;
	int		f;

	f = get_weapon_frame(&ctx->player);
	validate_tex_sizes(ctx, ctx->player.weapon_t, MAXWFRAME);
	start.x = (WIDTH / 2.0) - ((ctx->player.weapon_w * 3) / 2.0) + 160;
	start.y = HEIGHT - (ctx->player.weapon_h * 3);
	coord.x = -1;
	while (++coord.x < ctx->player.weapon_w * 3)
	{
		coord.y = -1;
		while (++coord.y < ctx->player.weapon_h * 3)
		{
			color = get_texture_pixel(&ctx->player.weapon_t[f],
					coord.x / 3, coord.y / 3);
			if (color != ERASE_C)
				safe_draw(ctx, start, color, coord);
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
			hit = fabs(ctx->player.dir.x * delta.y - ctx->player.dir.y
					* delta.x);
			if (dot > 0 && hit < 0.5 && ctx->sprites.arr[i].dist < 50.0)
			{
				ctx->sprites.arr[i].type = T_NULL;
				ctx->dead_moinu++;
			}
		}
	}
	check_alive_moine(ctx);
}
