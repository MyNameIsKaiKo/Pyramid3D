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

// void	check_alive_moine(t_ctx *ctx)
// {
// 	int	i;
// 	int	x;
// 	int	y;

// 	i = -1;
// 	while (++i < ctx->sprites.count)
// 	{
// 		if (ctx->sprites.arr[i].type == T_MOINE)
// 			return ;
// 	}
// 	y = -1;
// 	while (++y < ctx->map->y)
// 	{
// 		x = -1;
// 		while (++x < ctx->map->x)
// 		{
// 			if (ctx->map->map_tab[y][x] == '6')
// 				ctx->map->map_tab[y][x] = '0';
// 		}
// 	}
// }

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
			if (ctx->dead_moinu >= ctx->n_moinu && ctx->dstate == NULL_DOOR && ctx->map->map_tab[y][x] == '6')
			{
				ctx->map->map_tab[y][x] = 'o';
				ctx->dstate = OPEN_DOOR;
			}
			x++;
		}
		y++;
	}
}
