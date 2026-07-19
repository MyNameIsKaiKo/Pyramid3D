/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 15:42:32 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/19 16:06:01 by ldepenne         ###   ########.fr       */
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

	for (int i = START_X; i < 240; i++)
		my_mlx_pixel_put(ctx, i, START_X, 0xffff00ff);
	for (int i = START_Y;  i < 240; i++)
	{
		my_mlx_pixel_put(ctx, START_Y, i, 0xffff00ff);
		my_mlx_pixel_put(ctx, 240, i, 0xffff00ff);
	}
	for (int i = START_X; i < 240; i++)
		my_mlx_pixel_put(ctx, i, 240, 0xffff00ff);

	angle = atan2(ctx->player.dir.y, ctx->player.dir.x);

	top_pt.x = ctx->player.dir.x * 4 + 130;
	top_pt.y = ctx->player.dir.y * 4 + 130;
	right_pt.x = ctx->player.dir.x - 8 * cos(angle + 0.6) + 130;
	right_pt.y = ctx->player.dir.y - 8 * sin(angle + 0.6) + 130;
	left_pt.x = ctx->player.dir.x - 8 * cos(angle - 0.6) + 130;
	left_pt.y = ctx->player.dir.y - 8 * sin(angle - 0.6) + 130;

	my_mlx_pixel_put(ctx, top_pt.x, top_pt.y, 0xffff00ff);
	my_mlx_pixel_put(ctx, right_pt.x, right_pt.y, 0xffff00ff);
	my_mlx_pixel_put(ctx, left_pt.x, left_pt.y, 0xffff00ff);

	t_vec2 pt;

	pt.y = 124;
	while (pt.y != 136)
	{
		pt.x = 124;
		while (pt.x != 136)
		{
			if (is_in_triangle(pt, top_pt, right_pt, left_pt) == 1)
				my_mlx_pixel_put(ctx, pt.x, pt.y, 0xffff0000);
			pt.x++;
		}
		pt.y++;
	}
}
