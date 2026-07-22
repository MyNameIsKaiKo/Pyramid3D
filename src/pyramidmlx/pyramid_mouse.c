/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:36:35 by jleray            #+#    #+#             */
/*   Updated: 2026/07/18 11:36:35 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	mouse_init(t_ctx *ctx)
{
	mlx_mouse_hide(ctx->mlx, ctx->win);
	ctx->mouse.sensivity = 0.0001;
}

int	mouse_handler(int x, int y, t_ctx *ctx)
{
	static int	center_x = WIDTH / 2;
	static int	center_y = HEIGHT / 2;
	t_vec2		delta;
	double		tetha;

	if (x == center_x && y == center_y)
		return (0);
	delta.x = x - center_x;
	tetha = (int)delta.x * ctx->mouse.sensivity;
	rotate_vector(ctx, tetha);
	mlx_mouse_move(ctx->mlx, ctx->win, center_x, center_y);
	return (0);
}
