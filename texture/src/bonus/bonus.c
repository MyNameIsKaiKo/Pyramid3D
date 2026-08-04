/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:57:27 by jleray            #+#    #+#             */
/*   Updated: 2026/07/30 19:24:11 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_bonus(t_ctx *ctx)
{
	print_minimap(ctx);
	render_all_sprites(ctx);
	draw_gun(ctx);
}

void	init_bonus(t_ctx *ctx)
{
	ctx->dstate = NULL_DOOR;
	load_sprite(ctx);
	init_player_bonus(ctx);
}
