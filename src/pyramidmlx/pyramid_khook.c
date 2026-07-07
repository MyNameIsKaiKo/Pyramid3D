/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_khook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:38:42 by jleray            #+#    #+#             */
/*   Updated: 2026/06/25 19:38:42 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pyramid_mlx.h"

int	close_app(t_map *map)
{
	mlx_loop_end(map->mlx);
	return (0);
}

static int	player_move(int keycode, t_map *map)
{
	t_player	*player;

	player = &map->player;
	if (keycode == K_W)
		player->moves.forward = 1;
	if (keycode == K_S)
		player->moves.backward = 1;
	if (keycode == K_A)
		player->moves.left = 1;
	if (keycode == K_D)
		player->moves.right = 1;
	if (keycode == K_LEFT)
		player->moves.left_turn = 1;
	if (keycode == K_RIGHT)
		player->moves.right_turn = 1;
	return (0);
}

int	handlekey_press(int keycode, void *map)
{
	if (keycode == K_ESC)
		close_app(map);
	else
		player_move(keycode, map);
	return (0);
}

int	handlekey_release(int keycode, void *map)
{
	(void)keycode;
	(void)map;
	return (0);
}
