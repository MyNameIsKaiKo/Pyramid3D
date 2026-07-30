/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:42:08 by jb                #+#    #+#             */
/*   Updated: 2026/07/30 19:52:26 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	early_door_check(t_ctx *ctx)
{
	int	y;
	int	x;

	y = 0;
	while (y < ctx->map->y)
	{
		x = 0;
		while (x < ctx->map->x)
		{
			if (ctx->n_moinu == 0 && ctx->map->map_tab[y][x] == '6'
					&& ctx->dstate == NULL_DOOR)
			{
				ctx->dstate = OPEN_DOOR;
				ctx->map->map_tab[y][x] = 'o';
			}
			x++;
		}
		y++;
	}
}

void	door_swap(t_ctx *ctx, char old, char new)
{
	int	y;
	int	x;

	y = 0;
	while (y < ctx->map->y)
	{
		x = 0;
		while (x < ctx->map->x)
		{
			if (ctx->map->map_tab[y][x] == old)
				ctx->map->map_tab[y][x] = new;
			x++;
		}
		y++;
	}
}

void	check_alive_moine(t_ctx *ctx)
{
	int	y;
	int	x;

	y = 0;
	while (y < ctx->map->y)
	{
		x = 0;
		while (x < ctx->map->x)
		{
			if (ctx->dead_moinu >= ctx->n_moinu && ctx->dstate == NULL_DOOR
				&& ctx->map->map_tab[y][x] == '6')
			{
				ctx->map->map_tab[y][x] = 'o';
				ctx->dstate = OPEN_DOOR;
			}
			x++;
		}
		y++;
	}
}
