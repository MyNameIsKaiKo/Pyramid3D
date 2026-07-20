/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 15:42:32 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/20 19:47:28 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//ratio = 0.275 = (220 / 800)

static int	relative_pos(t_vec2 pt, t_vec2 sum_a, t_vec2 sum_b)
{
	int	result;

	result = ((pt.x - sum_b.x) * (sum_a.y - sum_b.y) -\
		(sum_a.x - sum_b.x) * (pt.y - sum_b.y));
	return (result);
}

static int	is_in_triangle(t_vec2 pt, t_vec2 sum1, t_vec2 sum2, t_vec2 sum3)
{
	int	edges1;
	int	edges2;
	int	edges3;
	int	has_neg;
	int	has_pos;

	edges1 = relative_pos(pt, sum1, sum2);
	edges2 = relative_pos(pt, sum2, sum3);
	edges3 = relative_pos(pt, sum3, sum1);
	has_neg = (edges1 < 0) || (edges2 < 0) || (edges3 < 0);
	has_pos = (edges1 > 0) || (edges2 > 0) || (edges3 > 0);
	return !(has_neg && has_pos);
}

void	print_minimap(t_ctx *ctx)
{
	double	angle;
	t_vec2	right_pt;
	t_vec2	left_pt;
	t_vec2	top_pt;

	for (int i = START_X; i < SIZE_MMAP; i++)
		my_mlx_pixel_put(ctx, i, START_X, 0xffff00ff);
	for (int i = START_Y;  i < SIZE_MMAP; i++)
	{
		my_mlx_pixel_put(ctx, START_Y, i, 0xffff00ff);
		my_mlx_pixel_put(ctx, SIZE_MMAP, i, 0xffff00ff);
	}
	for (int i = START_X; i < SIZE_MMAP; i++)
		my_mlx_pixel_put(ctx, i, SIZE_MMAP, 0xffff00ff);

	angle = atan2(ctx->player.dir.y, ctx->player.dir.x);

	top_pt.x = ctx->player.dir.x * 5 + 130;
	top_pt.y = ctx->player.dir.y * 5 + 130;
	right_pt.x = ctx->player.dir.x - 10 * cos(angle + 0.4) + 130;
	right_pt.y = ctx->player.dir.y - 10 * sin(angle + 0.4) + 130;
	left_pt.x = ctx->player.dir.x - 10 * cos(angle - 0.4) + 130;
	left_pt.y = ctx->player.dir.y - 10 * sin(angle - 0.4) + 130;

	// my_mlx_pixel_put(ctx, top_pt.x, top_pt.y, 0xffff00ff);
	// my_mlx_pixel_put(ctx, right_pt.x, right_pt.y, 0xffff00ff);
	// my_mlx_pixel_put(ctx, left_pt.x, left_pt.y, 0xffff00ff);

	t_vec2	current_block;
	t_vec2	result;

	current_block.y = START_Y;
	while (current_block.y < SIZE_MMAP)
	{
		result.y = (int)((current_block.y - START_Y) / SIZE_BLOCK) - 5;
		current_block.x = START_X;
		while (current_block.x < SIZE_MMAP)
		{
			result.x = (int)((current_block.x - START_X) / SIZE_BLOCK) - 5;
			if ((int)(ctx->player.pos.y + result.y) >= ctx->map->y
				|| (int)(ctx->player.pos.y + result.y) < 0
				|| (int)(ctx->player.pos.x + result.x) >= ctx->map->x
				|| (int)(ctx->player.pos.x + result.x) < 0)
				my_mlx_pixel_put(ctx, current_block.x, current_block.y, 0xff22605C);
			else if (ctx->map->map_tab[(int)(ctx->player.pos.y + result.y)][(int)(ctx->player.pos.x + result.x)] == FLOOR)
				my_mlx_pixel_put(ctx, current_block.x, current_block.y, 0xff056C5C);
			else
				my_mlx_pixel_put(ctx, current_block.x, current_block.y, 0xff80CCAD);
			current_block.x++;
		}
		current_block.y++;
	}

	t_vec2 pt;

	pt.y = 120;
	while (pt.y != 140)
	{
		pt.x = 120;
		while (pt.x != 140)
		{
			if (is_in_triangle(pt, top_pt, right_pt, left_pt) == 1)
				my_mlx_pixel_put(ctx, pt.x, pt.y, 0xffff0000);
			pt.x++;
		}
		pt.y++;
	}

}
