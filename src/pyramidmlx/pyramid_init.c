/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:47:22 by jleray            #+#    #+#             */
/*   Updated: 2026/07/08 14:47:22 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_init(t_ctx *ctx)
{
	ctx->mlx = mlx_init();
	if (!ctx->mlx)
		return (1);
	ctx->win = mlx_new_window(ctx->mlx, WIDTH, HEIGHT, "Pyramid3d");
	if (!ctx->win)
	{
		f_init(ctx);
		return (1);
	}
	ctx->img.img = mlx_new_image(ctx->mlx, WIDTH, HEIGHT);
	if (!ctx->img.img)
	{
		f_init(ctx);
		return (1);
	}
	ctx->img.addr = mlx_get_data_addr(ctx->img.img, &ctx->img.bits_per_pixel,
			&ctx->img.line_lenght, &ctx->img.endian);
	if (!ctx->img.addr)
	{
		f_init(ctx);
		return (1);
	}
	return (0);
}

int	pyramid_loop(t_ctx *ctx)
{
	if (map_init(ctx))
		return (1);
	texture_data(ctx);
	mouse_init(ctx);
	mlx_loop_hook(ctx->mlx, draw_frame, ctx);
	mlx_hook(ctx->win, 17, 0, close_app, ctx);
	mlx_hook(ctx->win, 6, 1L << 6, mouse_handler, ctx);
	mlx_hook(ctx->win, 2, 1L << 0, handlekey_press, ctx);
	mlx_hook(ctx->win, 3, 1L << 1, handlekey_release, ctx);
	mlx_mouse_hook(ctx->win, handlebutton, ctx);
	mlx_loop(ctx->mlx);
	mlx_mouse_show(ctx->mlx, ctx->win);
	mlx_destroy_image(ctx->mlx, ctx->img.img);
	tex_free(ctx);
	mlx_destroy_window(ctx->mlx, ctx->win);
	mlx_destroy_display(ctx->mlx);
	free(ctx->mlx);
	return (0);
}
