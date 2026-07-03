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
	t_ray	*ray;

	ray = &map->player.ray;
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map->map_tab[ray->map_y][ray->map_x] != '0')
			ray->hit = 1;
	}
}

void	calc_wall(t_map *map)
{
	t_ray	*ray;

	ray = &map->player.ray;
	if (ray->side == 0)
		ray->wall_dist = ray->sidedist_x - ray->deltadist_x;
	else if (ray->side == 1)
		ray->wall_dist = ray->sidedist_y - ray->deltadist_y;
}

void	draw_img(t_map *map, int x)
{
	t_ray	*ray;
	int		y;

	y = -1;
	ray = &map->player.ray;
	calc_drawing_value(ray);
	while (++y < HEIGHT)
	{
		if (y <= ray->draw_end && y >= ray->draw_start)
		{
			if (ray->side == 1)
				my_mlx_pixel_put(map, x, y, 0x00000000);
			else if (ray->side == 0)
				my_mlx_pixel_put(map, x, y, 0x00FFFFFF);
		}
		if (y < ray->draw_start)
			my_mlx_pixel_put(map, x, y, 0x00F02DC3);
		if (y > ray->draw_end)
			my_mlx_pixel_put(map, x, y, 0x00F02DFF);
	}
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
		draw_img(map, x);
		map->player.ray.hit = 0;
		x++;
	}
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	return (0);
}
