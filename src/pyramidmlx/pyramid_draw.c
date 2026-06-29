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
	t_ray	*ray;

	ray = &map->player.ray;
	ray->camera_x = 2.0 * x / (double)WIDTH - 1.0;
	ray->dir_x = map->player.dir.x + map->player.plane.x * ray->camera_x;
	ray->dir_y = map->player.dir.y + map->player.plane.y * ray->camera_x;
	ray->map_x = (int)map->player.pos.x;
	ray->map_y = (int)map->player.pos.y;
	calc_deltadist(ray);
	calc_sidedist(ray, map);
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
