/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jb <marvin@d42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:42:08 by jb                #+#    #+#             */
/*   Updated: 2026/07/27 20:42:08 by jb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_alive_moine(t_ctx *ctx)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while(++i < ctx->sprites.count)
	{
		if (ctx->sprites.arr[i].type == T_MOINE)
			return ;
	}
	y = -1;
	while (++y < ctx->map->y)
	{
		x = -1;
		while (++x < ctx->map->x)
		{
			if (ctx->map->map_tab[y][x] == '6')
				ctx->map->map_tab[y][x] = '0';
		}
	}
}
