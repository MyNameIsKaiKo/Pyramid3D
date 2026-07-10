/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:17:22 by jleray            #+#    #+#             */
/*   Updated: 2026/07/10 13:29:13 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	my_mlx_pixel_put(t_ctx *ctx, int x, int y, int color)
{
	char	*dst;

	dst = ctx->img.addr + (y * ctx->img.line_lenght + x
			* (ctx->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
