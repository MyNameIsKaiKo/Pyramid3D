/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_air.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:47:31 by jleray            #+#    #+#             */
/*   Updated: 2026/07/18 19:47:31 by jleray           ###   ########.fr       */
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
				0xFF00AA);
		i++;
	}
	i = -size;
	while (i <= size)
	{
		if (i != 0)
			my_mlx_pixel_put(ctx, (int)(center.x), (int)(center.y + i),
				0xFF00AA);
		i++;
	}
}
