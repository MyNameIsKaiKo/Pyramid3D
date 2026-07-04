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
	t_player	*player;

	player = &map->player;
	player->pos = map->starting_coord;
	player->dir.x = -1.0;
	player->dir.y = 0.0;
	player->plane.x = 0.0;
	player->plane.y = 0.66;
	player->rotation_speed = 0.1;
	player->time = 0;
	player->old_time = player->time;
	player->velocity = 0.1;
	player->moves.backward = 0;
	player->moves.forward = 0;
	player->moves.left = 0;
	player->moves.right = 0;
	player->moves.left_turn = 0;
	player->moves.right_turn = 0;
}

int	player_moved(t_player *player)
{
	if (player->moves.backward || player->moves.forward || player->moves.left
		|| player->moves.right)
		return (1);
	if (player->moves.left_turn || player->moves.right_turn)
		return (1);
	return (0);
}

void	apply_rotation(t_map *map)
{
	t_player	*player;

	player = &map->player;
	if (player->moves.left_turn)
	{
		rotate_vector(map, player->rotation_speed);
		player->moves.left_turn = 0;
	}
	else if (player->moves.right_turn)
	{
		rotate_vector(map, player->rotation_speed * -1);
		player->moves.right_turn = 0;
	}
}

void	apply_movement(t_map *map)
{
	t_player	*player;

	player = &map->player;
	apply_rotation(map);
	if (player->moves.forward)
		player_forward(map);
	if (player->moves.backward)
		player_backward(map);
	if (player->moves.left)
		player_left(map);
	if (player->moves.right)
		player_right(map);
}
