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
#include "mlx.h"

static void	fill_texs(char **texs)
{
	texs[0] = ft_strdup("texture/assets/lutin/lutin1.xpm");
	texs[1] = ft_strdup("texture/assets/lutin/lutin2.xpm");
	texs[2] = ft_strdup("texture/assets/lutin/lutin3.xpm");
	texs[3] = ft_strdup("texture/assets/lutin/lutin4.xpm");
	texs[4] = ft_strdup("texture/assets/lutin/lutin1.xpm");
}

static void free_texts(char **texs)
{
	int i;

	i = 0;
	while (i < 5)
	{
		free(texs[i]);
		i++;
	}
	return ;
}

void	false_lutin(t_ctx *ctx)
{
	int w;
	int h;
	char *texs[5];
	int i;

	i = 0;
	fill_texs(texs);
	ctx->lutin.pos.x = 3.5;
	ctx->lutin.pos.y = 3.5;
	ctx->lutin.frame = 0;
	while (i < 5)
	{
		ctx->lutin.tex[i].img = mlx_xpm_to_image(ctx->mlx, &texs[i], &w, &h);
		ctx->lutin.tex[i].addr = mlx_get_data_addr(ctx->lutin.tex[i].img,
				&ctx->lutin.tex[i].bits_per_pixel,
				&ctx->lutin.tex[i].line_lenght,
				&ctx->lutin.tex[i].endian);
	}
	free_texts(texs);
}
