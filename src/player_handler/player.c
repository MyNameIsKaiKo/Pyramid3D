/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:20:00 by jleray            #+#    #+#             */
/*   Updated: 2026/07/23 15:36:06 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	set_oriant(t_ctx *ctx)
{
	t_player	*player;

	player = &ctx->player;
	if (ctx->map->p_orient == 'N')
		set_north(player);
	if (ctx->map->p_orient == 'S')
		set_south(player);
	if (ctx->map->p_orient == 'E')
		set_east(player);
	if (ctx->map->p_orient == 'W')
		set_west(player);
	return ;
}

/** @brief player->plane.y represent the fov */
void	player_init(t_ctx *ctx)
{
	t_player	*player;

	player = &ctx->player;
	player->pos = ctx->map->starting_coord;
	set_oriant(ctx);
	player->rotation_speed = 0.1;
	player->time = 0;
	player->old_time = player->time;
	player->veloville = 0.1;
	player->moves.backward = 0;
	player->moves.forward = 0;
	player->moves.left = 0;
	player->moves.right = 0;
	player->moves.left_turn = 0;
	player->moves.right_turn = 0;
}

int	player_moved(t_player *player)
{
	if (player->moves.backward || player->moves.forward || player->moves.left
		|| player->moves.right)
		return (1);
	if (player->moves.left_turn || player->moves.right_turn)
		return (1);
	return (0);
}

void	apply_rotation(t_ctx *ctx)
{
	t_player	*player;

	player = &ctx->player;
	if (player->moves.left_turn)
		rotate_vector(ctx, player->rotation_speed * -1);
	else if (player->moves.right_turn)
		rotate_vector(ctx, player->rotation_speed);
}

void	apply_movement(t_ctx *ctx)
{
	t_player	*player;

	player = &ctx->player;
	apply_rotation(ctx);
	if (player->moves.forward)
		player_forward(ctx);
	if (player->moves.backward)
		player_backward(ctx);
	if (player->moves.left)
		player_left(ctx);
	if (player->moves.right)
		player_right(ctx);
}
