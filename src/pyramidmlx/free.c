/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:26:37 by jleray            #+#    #+#             */
/*   Updated: 2026/06/25 19:26:37 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pyramid_mlx.h"

void	f_init(t_map *map)
{
	if (!map->img.addr)
	{
		mlx_destroy_image(map->mlx, map->img.img);
		mlx_destroy_window(map->mlx, map->win);
		free(map->mlx);
	}
	else if (!map->img.img)
	{
		mlx_destroy_window(map->mlx, map->win);
		free(map->mlx);
	}
	else if (!map->win)
		free(map->mlx);
	ft_putstr_fd("Malloc Error\n", 1);
}
