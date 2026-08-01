/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:42:08 by jb                #+#    #+#             */
/*   Updated: 2026/08/01 18:36:10 by ldepenne         ###   ########.fr       */
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

int	door_place(char **tab, size_t y, size_t x)
{
	char	top_case;
	char	left_case;
	char	right_case;
	char	bottom_case;

	top_case = tab[y - 1][x];
	left_case = tab[y][x - 1];
	right_case = tab[y][x + 1];
	bottom_case = tab[y + 1][x];
	if (!left_case || !right_case
		|| !top_case || !bottom_case)
		return (print_error("Door is in border of map"));
	if (left_case == EMPTY || right_case == EMPTY
		|| top_case == EMPTY
		|| bottom_case == EMPTY)
		return (print_error("Door is in border of map"));
	return (0);
}
