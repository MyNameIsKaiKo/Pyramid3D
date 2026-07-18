/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 22:40:46 by jleray            #+#    #+#             */
/*   Updated: 2026/07/07 22:46:06 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	player_forward(t_ctx *ctx)
{
	t_player	*player;
	t_vec2		*pos;
	t_vec2		*dir;
	double		speed;
	double		hitbox;

	player = &ctx->player;
	pos = &ctx->player.pos;
	dir = &player->dir;
	hitbox = 0.1;
	speed = player->veloville + hitbox;
	if (ctx->map->map_tab[(int)pos->y][(int)(pos->x + dir->x * speed)] == '0')
		pos->x += dir->x * speed;
	if (ctx->map->map_tab[(int)(pos->y + dir->y * speed)][(int)pos->x] == '0')
		pos->y += dir->y * speed;
}

void	player_backward(t_ctx *ctx)
{
	t_player	*player;
	t_vec2		*pos;
	t_vec2		*dir;
	double		speed;
	double		hitbox;

	player = &ctx->player;
	pos = &player->pos;
	dir = &player->dir;
	hitbox = 0.1;
	speed = player->veloville + hitbox;
	if (ctx->map->map_tab[(int)pos->y][(int)(pos->x - dir->x * speed)] == '0')
		pos->x -= dir->x * speed;
	if (ctx->map->map_tab[(int)(pos->y - dir->y * speed)][(int)pos->x] == '0')
		pos->y -= dir->y * speed;
}

void	player_left(t_ctx *ctx)
{
	t_player	*player;
	t_vec2		*pos;
	t_vec2		*plane;
	double		speed;
	double		hitbox;

	player = &ctx->player;
	pos = &player->pos;
	plane = &player->plane;
	hitbox = 0.1;
	speed = player->veloville + hitbox;
	if (ctx->map->map_tab[(int)pos->y][(int)(pos->x - plane->x * speed)] == '0')
		pos->x -= plane->x * speed;
	if (ctx->map->map_tab[(int)(pos->y - plane->y * speed)][(int)pos->x] == '0')
		pos->y -= plane->y * speed;
}

void	player_right(t_ctx *ctx)
{
	t_player	*player;
	t_vec2		*pos;
	t_vec2		*plane;
	double		speed;
	double		hitbox;

	player = &ctx->player;
	pos = &player->pos;
	plane = &player->plane;
	hitbox = 0.1;
	speed = player->veloville + hitbox;
	if (ctx->map->map_tab[(int)pos->y][(int)(pos->x + plane->x * speed)] == '0')
		pos->x += plane->x * speed;
	if (ctx->map->map_tab[(int)(pos->y + plane->y * speed)][(int)pos->x] == '0')
		pos->y += plane->y * speed;
}
