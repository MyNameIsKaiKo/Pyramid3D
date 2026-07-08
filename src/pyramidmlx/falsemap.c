/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   falsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 01:07:05 by jleray            #+#    #+#             */
/*   Updated: 2026/07/08 13:37:49 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fill_fmap(t_ctx *ctx)
{
	ctx->map->map_tab = malloc(sizeof(char *) * 11);
	ctx->map->map_tab[0] = ft_strdup("1111111111");
	ctx->map->map_tab[1] = ft_strdup("1000000001");
	ctx->map->map_tab[2] = ft_strdup("1000011001");
	ctx->map->map_tab[3] = ft_strdup("1000011001");
	ctx->map->map_tab[4] = ft_strdup("1001111001");
	ctx->map->map_tab[5] = ft_strdup("1001100001");
	ctx->map->map_tab[6] = ft_strdup("1001111001");
	ctx->map->map_tab[7] = ft_strdup("1000011111");
	ctx->map->map_tab[8] = ft_strdup("1000000001");
	ctx->map->map_tab[9] = ft_strdup("1111111111");
	ctx->map->map_tab[10] = ft_strdup("\0");
	ctx->map->starting_coord.x = 5.5;
	ctx->map->starting_coord.y = 8.5;
	ctx->map->width = 10;
	ctx->map->height = 10;
	return ;
}

void	texture_data(t_ctx *ctx)
{
	int		i;
	int		w;
	int		h;
	char	*paths[4];

	i = 0;
	paths[0] = ft_strdup("./src/texture/texture1.xpm");
	paths[1] = ft_strdup("./src/texture/texture2.xpm");
	paths[2] = ft_strdup("./src/texture/texture3.xpm");
	paths[3] = ft_strdup("./src/texture/texture4.xpm");
	while (i < 4)
	{
		ctx->wall_tex[i].img = mlx_xpm_file_to_image(ctx->mlx, paths[i], &w,
				&h);
		ctx->wall_tex[i].addr = mlx_get_data_addr(ctx->wall_tex[i].img,
				&ctx->wall_tex[i].bits_per_pixel, &ctx->wall_tex[i].line_lenght,
				&ctx->wall_tex[i].endian);
		i++;
	}
	ctx->tex.height = h;
	ctx->tex.witdh = w;
	i = -1;
	while (++i < 4)
		free(paths[i]);
}
