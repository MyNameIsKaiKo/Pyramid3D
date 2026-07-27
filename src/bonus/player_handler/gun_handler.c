/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 16:00:15 by jleray            #+#    #+#             */
/*   Updated: 2026/07/26 16:24:44 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	load_sp_frame(t_ctx *ctx, char *path, t_img *tex)
{
	int	w;
	int	h;

	tex->img = mlx_xpm_file_to_image(ctx->mlx, path, &w, &h);
	if (!tex->img)
		printf("\n\nerror with the texture \"%s\"\n\n", path);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_lenght, &tex->endian);
	if (!tex->addr)
		printf("\n\nerror with the texture \"%s\"\n\n", path);
	ctx->player.weapon_h = h;
	ctx->player.weapon_w = w;
}

void	false_gun(t_ctx *ctx)
{
	t_player	*player;
	int			i;

	i = -1;
	player = &ctx->player;
	player->weapon_p[0] = "./texture/assets/slingshot/slingshot.xpm";
	player->weapon_p[1] = "./texture/assets/slingshot/slingshot2.xpm";
	player->weapon_p[2] = "./texture/assets/slingshot/slingshot3.xpm";
	while (++i < MAXWFRAME)
		load_sp_frame(ctx, player->weapon_p[i], &player->weapon_t[i]);
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
	t_vec2		start;
	int			x;
	int			y;
	int			color;
	int			f;

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
			if (color != 0x0000FF)
				my_mlx_pixel_put(ctx, start.x + x, start.y + y, color);
		}
	}
}
