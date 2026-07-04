/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 00:35:59 by jleray            #+#    #+#             */
/*   Updated: 2026/07/04 00:35:59 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pyramid_mlx.h"

// player->plane.y represent the fov
void	player_init(t_map *map)
{
	t_player *player;

	player = &map->player;
	player->pos = map->starting_coord;
	player->dir.x = -1.0;
	player->dir.y = 0.0;
	player->plane.x = 0.0;
	player->plane.y = 0.66;
	player->rotation_speed = 1;
	player->time = 0;
	player->old_time = player->time;
	player->velocity = 1;
}
