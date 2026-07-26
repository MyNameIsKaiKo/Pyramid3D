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
	player->weapon_p[0] = "./texture/grandRACCOON.xpm";
	player->weapon_p[1] = "./texture/texture1.xpm";
	player->weapon_p[2] = "./texture/texture4.xpm";
	while (++i < MAXWFRAME)
		load_sp_frame(ctx, player->weapon_p[i], &player->weapon_t[i]);
}

void	draw_gun(t_ctx *ctx)
{
	t_player	*player;
	t_vec2		start;
	int			x;
	int			y;
	int			color;

	player = &ctx->player;
	start.x = WIDTH - player->weapon_w;
	start.y = HEIGHT - player->weapon_h;
	x = -1;
	while (++x < player->weapon_w)
	{
		y = -1;
		while (++y < player->weapon_h)
		{
			color = get_texture_pixel(&player->weapon_t[0], x, y);
			if (color != 0x0000FF)
				my_mlx_pixel_put(ctx, start.x + x, start.y + y, color);
		}
	}
}
