/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:31:33 by ldepenne          #+#    #+#             */
/*   Updated: 2026/08/02 19:55:14 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub_struct_def.h"

/** @return 1 if is wall or 0 is not wall */
bool	iswall(t_tile_type c)
{
	return (c >= WALL && c < DOOR6);
}

int	first_line(char **tab, size_t y)
{
	size_t	x;
	char	*fst_line;

	x = 0;
	fst_line = tab[y];
	while (fst_line[x])
	{
		if (!(iswall(fst_line[x]) || fst_line[x] == EMPTY))
			return (1);
		x++;
	}
	return (0);
}

int	issprite(t_tile_type c)
{
	return (c >= LUTIN && c <= PIRATE);
}

int	close_map(char **tab, size_t y, size_t x)
{
	char	top_case;
	char	left_case;
	char	right_case;
	char	bottom_case;

	top_case = tab[y - 1][x];
	left_case = tab[y][x - 1];
	right_case = tab[y][x + 1];
	bottom_case = tab[y + 1][x];
	if ((!iswall(top_case) && top_case != FLOOR && top_case != DOOR6
			&& !issprite(top_case) && !isplayer(top_case))
		|| (!iswall(left_case) && left_case != FLOOR && left_case != DOOR6
			&& !issprite(left_case) && !isplayer(left_case))
		|| (!iswall(right_case) && right_case != FLOOR && right_case != DOOR6
			&& !issprite(right_case) && !isplayer(right_case))
		|| (!iswall(bottom_case) && bottom_case != FLOOR && bottom_case != DOOR6
			&& !issprite(bottom_case) && !isplayer(bottom_case)))
		return (print_error("Map is open in close map"));
	return (0);
}

int	data_sprite(t_ctx *ctx, size_t y, size_t x, t_sp_type type)
{
	t_sprites	*sprites;

	sprites = &ctx->sprites;
	if (sprites->count >= NB_BONUS_TEXTURES)
		return (print_error("To many sprites in map"));
	sprites->arr[sprites->count].pos.x = x + 0.5;
	sprites->arr[sprites->count].pos.y = y + 0.5;
	sprites->arr[sprites->count].type = type;
	ctx->map->parse_map[y][x] = FLOOR;
	sprites->count++;
	return (0);
}
