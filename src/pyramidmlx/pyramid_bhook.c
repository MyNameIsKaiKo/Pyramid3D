/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_bhook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:35:20 by jleray            #+#    #+#             */
/*   Updated: 2026/07/07 22:31:54 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	handlebutton(int button, int x, int y, void *data)
{
	t_ctx *ctx;
	(void)x;
	(void)y;

	ctx = (t_ctx *)data;
	if (button == 1)
		ctx->player.wstate = W_HOLD;
	return (0);
}

int	handlebutton_release(int button, int x, int y, void *data)
{
	t_ctx *ctx;
	(void)x;
	(void)y;

	ctx = (t_ctx *)data;
	if (button == 1 && ctx->player.wstate == W_HOLD)
	{
		ctx->player.wstate = W_FIRE;
		shoot_weapon(ctx);
		ft_putstr_fd("RHUM IN COMMING\n", 1);
	}
	return (0);
}
