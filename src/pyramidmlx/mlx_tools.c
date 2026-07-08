/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2026/07/08 13:45:44 by ldepenne         ###   ########.fr       */
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
