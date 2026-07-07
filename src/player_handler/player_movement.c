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
	double		hitbox;

	player = &map->player;
	pos = &map->player.pos;
	dir = &player->dir;
	hitbox = 0.1;
	speed = player->velocity + hitbox;
	if (map->map_tab[(int)pos->y][(int)(pos->x + dir->x * speed)] == '0')
		pos->x += dir->x * speed;
	if (map->map_tab[(int)(pos->y + dir->y * speed)][(int)pos->x] == '0')
		pos->y += dir->y * speed;
	player->moves.forward = 0;
}

void	player_backward(t_map *map)
{
	t_player	*player;
	t_pos		*pos;
	t_dir		*dir;
	double		speed;
	double		hitbox;

	player = &map->player;
	pos = &player->pos;
	dir = &player->dir;
	hitbox = 0.1;
	speed = player->velocity + hitbox;
	if (map->map_tab[(int)pos->y][(int)(pos->x - dir->x * speed)] == '0')
		pos->x -= dir->x * speed;
	if (map->map_tab[(int)(pos->y - dir->y * speed)][(int)pos->x] == '0')
		pos->y -= dir->y * speed;
	player->moves.backward = 0;
}

void	player_left(t_map *map)
{
	t_player	*player;
	t_pos		*pos;
	t_plane		*plane;
	double		speed;
	double		hitbox;

	player = &map->player;
	pos = &player->pos;
	plane = &player->plane;
	hitbox = 0.1;
	speed = player->velocity + hitbox;
	if (map->map_tab[(int)pos->y][(int)(pos->x - plane->x * speed)] == '0')
		pos->x -= plane->x * speed;
	if (map->map_tab[(int)(pos->y - plane->y * speed)][(int)pos->x] == '0')
		pos->y -= plane->y * speed;
	player->moves.left = 0;
}

void	player_right(t_map *map)
{
	t_player	*player;
	t_pos		*pos;
	t_plane		*plane;
	double		speed;
	double		hitbox;

	player = &map->player;
	pos = &player->pos;
	plane = &player->plane;
	hitbox = 0.1;
	speed = player->velocity + hitbox;
	if (map->map_tab[(int)pos->y][(int)(pos->x + plane->x * speed)] == '0')
		pos->x += plane->x * speed;
	if (map->map_tab[(int)(pos->y + plane->y * speed)][(int)pos->x] == '0')
		pos->y += plane->y * speed;
	player->moves.right = 0;
}
