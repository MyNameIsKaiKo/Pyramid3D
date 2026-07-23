/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   false_lutin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 17:43:29 by jleray            #+#    #+#             */
/*   Updated: 2026/07/22 17:43:29 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	load_sp_frame(t_ctx *ctx, char *path, t_img *tex)
{
	int	w;
	int	h;

	tex->img = mlx_xpm_file_to_image(ctx->mlx, path, &w, &h);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_lenght, &tex->endian);
}

void	false_lutin(t_ctx *ctx)
{
	load_sp_frame(ctx, "texture/assets/lutin/lutin1.xpm",
		&ctx->sprites.lutin_t[0]);
	load_sp_frame(ctx, "texture/assets/lutin/lutin2.xpm",
		&ctx->sprites.lutin_t[1]);
	load_sp_frame(ctx, "texture/assets/lutin/lutin3.xpm",
		&ctx->sprites.lutin_t[2]);
	load_sp_frame(ctx, "texture/assets/lutin/lutin4.xpm",
		&ctx->sprites.lutin_t[3]);
	load_sp_frame(ctx, "texture/assets/lutin/lutin5.xpm",
		&ctx->sprites.lutin_t[4]);
	ctx->sprites.count = 1;
	ctx->sprites.arr[0].type = LUTIN;
	ctx->sprites.arr[0].pos.x = 3.5;
	ctx->sprites.arr[0].pos.y = 3.5;
}
