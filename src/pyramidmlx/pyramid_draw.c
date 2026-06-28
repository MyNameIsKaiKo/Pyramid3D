/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 18:23:49 by jleray            #+#    #+#             */
/*   Updated: 2026/06/28 18:23:49 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pyramid_mlx.h"

void	setup_ray_for_col(t_map *map, int x)
{
	(void)map;
	(void)x;
}

void	exec_dda(t_map *map)
{
	(void)map;
}

void	calc_wall(t_map *map)
{
	(void)map;
}

void	draw_img(t_map *map)
{
	(void)map;
}

int	draw_frame(t_map *map)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		setup_ray_for_col(map, x);
		exec_dda(map);
		calc_wall(map);
		draw_img(map);
	}
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	return (0);
}
