/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_bhook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:35:20 by jleray            #+#    #+#             */
/*   Updated: 2026/07/29 10:50:12 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	handlebutton(int button, int x, int y, void *data)
{
	t_ctx	*ctx;

	(void) x;
	(void) y;
	ctx = (t_ctx *)data;
	if (button == 1)
		ctx->player.wstate = W_HOLD;
	if (button == 2)
		handle_mouse_state(ctx);
	return (0);
}

int	handlebutton_release(int button, int x, int y, void *data)
{
	t_ctx	*ctx;

	(void) x;
	(void) y;
	ctx = (t_ctx *)data;
	if (BONUS && button == 1 && ctx->player.wstate == W_HOLD)
	{
		ctx->player.wstate = W_FIRE;
		shoot_weapon(ctx);
		ft_putstr_fd("RHUM IN COMMING\n", 1);
	}
	return (0);
}
