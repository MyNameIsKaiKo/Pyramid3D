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

#include "../includes/pyramid_mlx.h"

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
