/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_air.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:47:31 by jleray            #+#    #+#             */
/*   Updated: 2026/07/26 13:36:21 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_crossair(t_ctx *ctx)
{
	t_vec2		center;
	static int	size = 10;
	int			i;

	center.x = (int)WIDTH / 2;
	center.y = (int)HEIGHT / 2;
	i = -size;
	while (i <= size)
	{
		if (i != 0)
			my_mlx_pixel_put(ctx, (int)(center.x + i), (int)(center.y),
				MCOLOR_WALL);
		i++;
	}
	i = -size;
	while (i <= size)
	{
		if (i != 0)
			my_mlx_pixel_put(ctx, (int)(center.x), (int)(center.y + i),
				MCOLOR_WALL);
		i++;
	}
}
