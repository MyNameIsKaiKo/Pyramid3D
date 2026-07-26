/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:36:27 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/26 21:15:39 by ldepenne         ###   ########.fr       */
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

static void	display_sprite(t_ctx *ctx, t_vec2 result, t_vec2 curr_block)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = (int)(ctx->player.pos.y + result.y);
	x = (int)(ctx->player.pos.x + result.x);
	while (i < NB_BONUS_TEXTURES)
	{
		if (y == (int)ctx->sprites.arr[i].pos.y
			&& x == (int)ctx->sprites.arr[i].pos.x)
		{
			if (ctx->sprites.arr[i].type == T_LUTIN)
				my_mlx_pixel_put(ctx, curr_block.x, curr_block.y, MCOLOR_LUTIN);
			else if (ctx->sprites.arr[i].type == T_MOINE)
				my_mlx_pixel_put(ctx, curr_block.x, curr_block.y, MCOLOR_MOINU);
			else if (ctx->sprites.arr[i].type == T_PIRATE)
				my_mlx_pixel_put(ctx, curr_block.x, curr_block.y,
					MCOLOR_PIRATE);
		}
		i++;
	}
}

static void	display_background(t_ctx *ctx, t_vec2 result, t_vec2 curr_block)
{
	int		y;
	int		x;

	y = (int)(ctx->player.pos.y + result.y);
	x = (int)(ctx->player.pos.x + result.x);
	if (is_inmap(ctx, result))
		my_mlx_pixel_put(ctx, curr_block.x, curr_block.y, MCOLOR_VOID);
	else if (ctx->map->map_tab[y][x] == FLOOR)
		my_mlx_pixel_put(ctx, curr_block.x, curr_block.y, MCOLOR_FLOOR);
	else
		my_mlx_pixel_put(ctx, curr_block.x, curr_block.y, MCOLOR_WALL);
}

void	display_map(t_ctx *ctx)
{
	t_vec2	curr_block;
	t_vec2	result;

	curr_block.y = START_Y;
	while (curr_block.y < SIZE_MMAP)
	{
		result.y = (int)((curr_block.y - START_Y) / SIZE_BLOCK) - 5;
		curr_block.x = START_X;
		while (curr_block.x < SIZE_MMAP)
		{
			result.x = (int)((curr_block.x - START_X) / SIZE_BLOCK) - 5;
			display_background(ctx, result, curr_block);
			display_sprite(ctx, result, curr_block);
			curr_block.x++;
		}
		curr_block.y++;
	}
}
