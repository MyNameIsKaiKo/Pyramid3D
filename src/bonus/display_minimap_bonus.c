/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:36:27 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/26 02:22:37 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	is_inmap(t_ctx *ctx, t_vec2 result)
{
	if ((int)(ctx->player.pos.y + result.y) >= ctx->map->y
		|| (int)(ctx->player.pos.y + result.y) < 0
		|| (int)(ctx->player.pos.x + result.x) >= ctx->map->x
		|| (int)(ctx->player.pos.x + result.x) < 0)
		return (1);
	return (0);
}

void	display_map(t_ctx *ctx)
{
	t_vec2	c_block;
	t_vec2	result;
	int		y;
	int		x;

	c_block.y = START_Y;
	while (c_block.y < SIZE_MMAP)
	{
		result.y = (int)((c_block.y - START_Y) / SIZE_BLOCK) - 5;
		c_block.x = START_X;
		while (c_block.x < SIZE_MMAP)
		{
			y = (int)(ctx->player.pos.y + result.y);
			x = (int)(ctx->player.pos.x + result.x);
			result.x = (int)((c_block.x - START_X) / SIZE_BLOCK) - 5;
			if (is_inmap(ctx, result))
				my_mlx_pixel_put(ctx, c_block.x, c_block.y, MCOLOR_EMPTY);
			else if (ctx->map->map_tab[(int)(ctx->player.pos.y + result.y)][(int)(ctx->player.pos.x + result.x)] == FLOOR)
				my_mlx_pixel_put(ctx, c_block.x, c_block.y, MCOLOR_FLOOR);
			else
				my_mlx_pixel_put(ctx, c_block.x, c_block.y, MCOLOR_WALL);
			int i = 0;
			while (i < NB_BONUS_TEXTURES)
			{
				if (y == (int)ctx->sprites.arr[i].pos.y && x == (int)ctx->sprites.arr[i].pos.x)
				{
					if (ctx->sprites.arr[i].type == T_LUTIN)
						my_mlx_pixel_put(ctx, c_block.x, c_block.y, MCOLOR_LUTIN);
					else if (ctx->sprites.arr[i].type == T_MOINE)
						my_mlx_pixel_put(ctx, c_block.x, c_block.y, MCOLOR_MOINU);
					else if (ctx->sprites.arr[i].type == T_PIRATE)
						my_mlx_pixel_put(ctx, c_block.x, c_block.y, MCOLOR_PIRATE);
				}
				i++;
			}
			c_block.x++;
		}
		c_block.y++;
	}
}
