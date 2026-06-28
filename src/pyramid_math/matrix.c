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
	t_player	player;
	double		old_x;
	double		x;
	double		y;

	player = map->player;
	old_x = player.dir.x;
	x = player.dir.x;
	y = player.dir.y;
	player.dir.x = ((old_x * cos(angle)) - (y * sin(angle)));
	player.dir.y = ((old_x * sin(angle) - (y * cos(angle))));
	return ;
}
