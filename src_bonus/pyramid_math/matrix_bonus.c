/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 13:15:23 by jleray            #+#    #+#             */
/*   Updated: 2026/07/10 13:29:13 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	rotate_vector(t_ctx *ctx, double angle)
{
	t_player	*player;
	double		old_dir_x;
	double		old_plane_x;

	player = &ctx->player;
	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(angle) - player->dir.y * sin(angle);
	player->dir.y = old_dir_x * sin(angle) + player->dir.y * cos(angle);
	old_plane_x = player->plane.x;
	player->plane.x = player->plane.x * cos(angle) - player->plane.y
		* sin(angle);
	player->plane.y = old_plane_x * sin(angle) + player->plane.y * cos(angle);
	return ;
}
