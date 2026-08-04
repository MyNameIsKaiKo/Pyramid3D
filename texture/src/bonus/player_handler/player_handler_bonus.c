/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handler_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 14:32:46 by jleray            #+#    #+#             */
/*   Updated: 2026/07/25 14:32:46 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_player_bonus(t_ctx *ctx)
{
	t_player	*player;

	player = &ctx->player;
	player->hp = 100;
}

void	player_take_damage(t_ctx *ctx, int amount)
{
	t_player	*player;

	player = &ctx->player;
	player->hp = player->hp - amount;
	if (player->hp <= 0)
	{
		ft_putstr_fd("YOU DIED! GAME OVER. \n", 1);
		close_app(ctx);
	}
}
