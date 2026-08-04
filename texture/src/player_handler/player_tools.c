/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:41:33 by jleray            #+#    #+#             */
/*   Updated: 2026/07/22 15:41:33 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_north(t_player *player)
{
	player->dir.x = 0.0;
	player->dir.y = -1.0;
	player->plane.x = 0.66;
	player->plane.y = 0.0;
}

void	set_south(t_player *player)
{
	player->dir.x = 0.0;
	player->dir.y = 1.0;
	player->plane.x = -0.66;
	player->plane.y = 0.0;
}

void	set_east(t_player *player)
{
	player->dir.x = 1.0;
	player->dir.y = 0.0;
	player->plane.x = 0.0;
	player->plane.y = 0.66;
}

void	set_west(t_player *player)
{
	player->dir.x = -1.0;
	player->dir.y = 0.0;
	player->plane.x = 0.0;
	player->plane.y = -0.66;
}
