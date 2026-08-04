/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 15:42:32 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/31 14:26:50 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	relative_pos(t_vec2 pt, t_vec2 sum_a, t_vec2 sum_b)
{
	int	result;

	result = ((pt.x - sum_b.x) * (sum_a.y - sum_b.y)
			- (sum_a.x - sum_b.x) * (pt.y - sum_b.y));
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
	return (!(has_neg && has_pos));
}

static void	display_player(t_ctx *ctx)
{
	double	angle;
	t_vec2	right_pt;
	t_vec2	left_pt;
	t_vec2	top_pt;
	t_vec2	pt;

	angle = atan2(ctx->player.dir.y, ctx->player.dir.x);
	top_pt.x = ctx->player.dir.x * 5 + 130;
	top_pt.y = ctx->player.dir.y * 5 + 130;
	right_pt.x = ctx->player.dir.x - 10 * cos(angle + 0.4) + 130;
	right_pt.y = ctx->player.dir.y - 10 * sin(angle + 0.4) + 130;
	left_pt.x = ctx->player.dir.x - 10 * cos(angle - 0.4) + 130;
	left_pt.y = ctx->player.dir.y - 10 * sin(angle - 0.4) + 130;
	pt.y = 120;
	while (pt.y != 140)
	{
		pt.x = 120;
		while (pt.x != 140)
		{
			if (is_in_triangle(pt, top_pt, right_pt, left_pt) == 1)
				my_mlx_pixel_put(ctx, pt.x, pt.y, MCOLOR_PLAYER);
			pt.x++;
		}
		pt.y++;
	}
}

void	print_minimap(t_ctx *ctx)
{
	display_map(ctx);
	display_player(ctx);
}
