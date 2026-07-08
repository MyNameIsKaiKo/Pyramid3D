/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 13:15:23 by jleray            #+#    #+#             */
/*   Updated: 2026/06/28 13:15:23 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pyramid_mlx.h"

void	rotate_vector(t_map *map, double angle)
{
	t_player	*player;
	double		old_dir_x;
	double		old_plane_x;

	player = &map->player;
	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(angle) - player->dir.y * sin(angle);
	player->dir.y = old_dir_x * sin(angle) + player->dir.y * cos(angle);
	old_plane_x = player->plane.x;
	player->plane.x = player->plane.x * cos(angle)
		- player->plane.y * sin(angle);
	player->plane.y = old_plane_x * sin(angle) + player->plane.y * cos(angle);
	return ;
}
