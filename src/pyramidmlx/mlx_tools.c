/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:17:22 by jleray            #+#    #+#             */
/*   Updated: 2026/07/08 14:17:22 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_ctx *ctx, int x, int y, int color)
{
	char	*dst;

	dst = ctx->img.addr + (y * ctx->img.line_lenght + x
			* (ctx->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
