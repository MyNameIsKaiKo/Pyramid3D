/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_scd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 02:43:16 by jleray            #+#    #+#             */
/*   Updated: 2026/07/05 02:43:16 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pyramid_mlx.h"

void	calc_tex_y(t_map *map)
{
	t_texture	*tex;

	tex = &map->tex;
	tex->y = (int)tex->start % tex->height;
	if (tex->y < 0)
		tex->y = 0;
	if (tex->y >= tex->height)
		tex->y = tex->height - 1;
}

void	get_tex_index(t_map *map)
{
	t_ray	*ray;

	ray = &map->player.ray;
	if (ray->side == 0 && ray->dir_x < 0)
		map->tex.index = 0;
	if (ray->side == 1 && ray->dir_y > 0)
		map->tex.index = 1;
	if (ray->side == 0 && ray->dir_x > 0)
		map->tex.index = 2;
	if (ray->side == 1 && ray->dir_y < 0)
		map->tex.index = 3;
}
