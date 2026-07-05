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

void	map_free(t_map *map)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		free(map->map_tab[i]);
		i++;
	}
	free(map->map_tab);
}

void	tex_free(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(map->mlx, map->wall_tex[i].img);
		i++;
	}
}
