/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 22:40:46 by jleray            #+#    #+#             */
/*   Updated: 2026/07/04 22:40:46 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pyramid_mlx.h"

void	player_forward(t_map *map)
{
	t_player	*player;
	t_pos		*pos;
	t_dir		*dir;
	double		speed;

	player = &map->player;
	pos = &map->player.pos;
	dir = &player->dir;
	speed = player->velocity;
	if (map->map_tab[(int)(pos->x + dir->x * speed)][(int)pos->y] == '0')
		pos->x += dir->x * speed;
	if (map->map_tab[(int)pos->x][(int)(pos->y + dir->y * speed)] == '0')
		pos->y += dir->y * speed;
	player->moves.forward = 0;
}

void	player_backward(t_map *map)
{
	t_player	*player;
	t_pos		*pos;
	t_dir		*dir;
	double		speed;

	player = &map->player;
	pos = &player->pos;
	dir = &player->dir;
	speed = player->velocity;
	if (map->map_tab[(int)(pos->x - dir->x * speed)][(int)pos->y] == '0')
		pos->x -= dir->x * speed;
	if (map->map_tab[(int)pos->x][(int)(pos->y - dir->y * speed)] == '0')
		pos->y -= dir->y * speed;
	player->moves.backward = 0;
}

void	player_left(t_map *map)
{
	t_player	*player;
	t_pos		*pos;
	t_plane		*plane;
	double		speed;

	player = &map->player;
	pos = &player->pos;
	plane = &player->plane;
	speed = player->velocity;
	if (map->map_tab[(int)(pos->x - plane->x * speed)][(int)pos->y] == '0')
		pos->x -= plane->x * speed;
	if (map->map_tab[(int)pos->x][(int)(pos->y - plane->y * speed)] == '0')
		pos->y -= plane->y * speed;
	player->moves.left = 0;
}

void	player_right(t_map *map)
{
	t_player	*player;
	t_pos		*pos;
	t_plane		*plane;
	double		speed;

	player = &map->player;
	pos = &player->pos;
	plane = &player->plane;
	speed = player->velocity;
	if (map->map_tab[(int)(pos->x + plane->x * speed)][(int)pos->y] == '0')
		pos->x += plane->x * speed;
	if (map->map_tab[(int)pos->x][(int)(pos->y + plane->y * speed)] == '0')
		pos->y += plane->y * speed;
	player->moves.right = 0;
}
