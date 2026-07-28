/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:57:27 by jleray            #+#    #+#             */
/*   Updated: 2026/07/27 17:57:27 by jleray           ###   ########.fr       */
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
	load_sprite(ctx);
	false_gun(ctx);
	init_player_bonus(ctx);
}
