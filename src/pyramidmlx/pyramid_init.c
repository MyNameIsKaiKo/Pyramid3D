/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:28:13 by jleray            #+#    #+#             */
/*   Updated: 2026/06/25 18:43:26 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pyramid_mlx.h"

int	map_init(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		return (1);
	map->win = mlx_new_window(map->mlx, WIDTH, HEIGHT, "Pyramid3d");
	if (!map->win)
	{
		f_init(map);
		return (1);
	}
	map->img.img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if (!map->img.img)
	{
		f_init(map);
		return (1);
	}
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel,
			&map->img.line_lenght, &map->img.endian);
	if (!map->img.addr)
	{
		f_init(map);
		return (1);
	}
	return (0);
}

int	pyramid_loop(t_map *map)
{
	if (map_init(map))
		return (1);
	texture_data(map);
	mlx_loop_hook(map->mlx, draw_frame, map);
	mlx_hook(map->win, 17, 0, close_app, map);
	mlx_hook(map->win, 2, 1l << 0, handlekey_press, map);
	mlx_hook(map->win, 3, 1L << 1, handlekey_release, map);
	mlx_mouse_hook(map->win, handlebutton, map);
	mlx_loop(map->mlx);
	mlx_destroy_image(map->mlx, map->img.img);
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	map_free(map);
	return (0);
}
