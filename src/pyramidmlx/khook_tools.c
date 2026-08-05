/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   khook_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 01:57:40 by jleray            #+#    #+#             */
/*   Updated: 2026/08/05 01:57:40 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct_def.h"
#include "mlx.h"

void	handle_mouse_state(t_ctx *ctx)
{
	ctx->mouse.is_free = !ctx->mouse.is_free;
	if (ctx->mouse.is_free)
		mlx_mouse_show(ctx->mlx, ctx->win);
	else
	{
		mlx_mouse_hide(ctx->mlx, ctx->win);
		mlx_mouse_move(ctx->mlx, ctx->win, WIDTH / 2, HEIGHT / 2);
	}
}

void	handle_door_state(t_ctx *ctx)
{
	if (ctx->dstate == OPEN_DOOR)
	{
		ctx->dstate = CLOSE_DOOR;
		door_swap(ctx, 'o', '6');
	}
	else if (ctx->dstate == CLOSE_DOOR)
	{
		ctx->dstate = OPEN_DOOR;
		door_swap(ctx, '6', 'o');
	}
}
