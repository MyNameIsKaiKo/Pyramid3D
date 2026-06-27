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
	(void)map;
	if (keycode == K_W)
		ft_putstr_fd("Go Forward\n", 1);
	if (keycode == K_S)
		ft_putstr_fd("Go Backward\n", 2);
	if (keycode == K_A)
		ft_putstr_fd("Go Left\n", 1);
	if (keycode == K_D)
		ft_putstr_fd("Go Right\n", 1);
	return (0);
}

int	handlekey_press(int keycode, void *map)
{
	if (keycode == K_ESC)
		close_app(map);
	if (keycode == K_W)
		player_move(keycode, map);
	return (0);
}

int	handlekey_release(int keycode, void *map)
{
	(void)keycode;
	(void)map;
	return (0);
}
