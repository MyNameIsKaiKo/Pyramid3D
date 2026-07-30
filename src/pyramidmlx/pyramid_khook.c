/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_khook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:26:13 by jleray            #+#    #+#             */
/*   Updated: 2026/07/30 19:37:39 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	close_app(t_ctx *ctx)
{
	mlx_loop_end(ctx->mlx);
	return (0);
}

static int	player_move(int keycode, t_ctx *ctx, int state)
{
	t_player	*player;

	player = &ctx->player;
	if (keycode == K_W)
		player->moves.forward = state;
	if (keycode == K_S)
		player->moves.backward = state;
	if (keycode == K_A)
		player->moves.left = state;
	if (keycode == K_D)
		player->moves.right = state;
	if (keycode == K_LEFT)
		player->moves.left_turn = state;
	if (keycode == K_RIGHT)
		player->moves.right_turn = state;
	return (0);
}

int	handlekey_press(int keycode, void *ctx)
{
	t_ctx	*ctx_pt;

	ctx_pt = (t_ctx *)ctx;
	if (keycode == K_ESC)
		close_app(ctx);
	if (BONUS && keycode == K_R)
		ctx_pt->player.wstate = W_HOLD;
	if (BONUS && keycode == K_Q)
	{
		if (ctx_pt->dstate == OPEN_DOOR)
			ctx_pt->dstate = CLOSE_DOOR;
		else if (ctx_pt->dstate == CLOSE_DOOR)
			ctx_pt->dstate = OPEN_DOOR;
	}
	else
		player_move(keycode, ctx, 1);
	return (0);
}

int	handlekey_release(int keycode, void *ctx)
{
	if (BONUS && keycode == K_R && ((t_ctx *)ctx)->player.wstate == W_HOLD)
	{
		((t_ctx *)ctx)->player.wstate = W_FIRE;
		shoot_weapon(ctx);
		ft_putstr_fd("RHUM IN COMMING\n", 1);
	}
	else
		player_move(keycode, ctx, 0);
	return (0);
}
