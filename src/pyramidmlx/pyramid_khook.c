/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_khook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:26:13 by jleray            #+#    #+#             */
/*   Updated: 2026/07/08 14:26:13 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	close_app(t_ctx *ctx)
{
	mlx_loop_end(ctx->mlx);
	return (0);
}

static int	player_move(int keycode, t_ctx *ctx)
{
	t_player	*player;

	player = &ctx->player;
	if (keycode == K_W)
		player->moves.forward = 1;
	if (keycode == K_S)
		player->moves.backward = 1;
	if (keycode == K_A)
		player->moves.left = 1;
	if (keycode == K_D)
		player->moves.right = 1;
	if (keycode == K_LEFT)
		player->moves.left_turn = 1;
	if (keycode == K_RIGHT)
		player->moves.right_turn = 1;
	return (0);
}

int	handlekey_press(int keycode, void *ctx)
{
	if (keycode == K_ESC)
		close_app(ctx);
	else
		player_move(keycode, ctx);
	return (0);
}

int	handlekey_release(int keycode, void *ctx)
{
	(void)keycode;
	(void)ctx;
	return (0);
}
