/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spirte_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:03:03 by jleray            #+#    #+#             */
/*   Updated: 2026/07/23 13:03:03 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_sprdist(t_ctx *ctx)
{
	int			i;
	t_sprites	*sprites;
	t_player	*player;

	sprites = &ctx->sprites;
	player = &ctx->player;
	i = 0;
	while (i < sprites->count)
	{
		sprites->arr[i].dist = pow(player->pos.x - sprites->arr[i].pos.x, 2)
			+ pow(player->pos.y - sprites->arr[i].pos.y, 2);
		i++;
	}
}

void	sort_sprdist(t_sprites *sprites)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = -1;
	while (++i < sprites->count - 1)
	{
		j = i;
		while (++j < sprites->count)
		{
			if (sprites->arr[i].dist < sprites->arr[j].dist)
			{
				tmp = sprites->arr[i];
				sprites->arr[i] = sprites->arr[j];
				sprites->arr[j] = tmp;
			}
		}
	}
}

t_vec2	get_delta(t_ctx *ctx, int i)
{
	t_vec2	delta;

	delta.x = ctx->sprites.arr[i].pos.x - ctx->player.pos.x;
	delta.y = ctx->sprites.arr[i].pos.y - ctx->player.pos.y;
	return (delta);
}
