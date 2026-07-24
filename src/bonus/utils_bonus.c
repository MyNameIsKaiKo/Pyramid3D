/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:31:33 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/24 18:06:15 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/** @return 1 if is wall or 0 is not wall */
bool	iswall(t_tile_type c)
{
	return (c >= WALL && c <= WALL6);
}

void draw_bonus(t_ctx *ctx)
{
	print_minimap(ctx);
	render_all_sprites(ctx);
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
	if (!iswall(top_case) && top_case != FLOOR)
		return (1);
	return (0);
}

void	data_sprite(t_ctx *ctx, size_t y, size_t x, t_sp_type type)
{
	t_sprites *sprites;

	sprites = &ctx->sprites;
	sprites->count++;
	sprites->arr[sprites->count].pos.x = x + 0.5;
	sprites->arr[sprites->count].pos.y = y + 0.5;
	sprites->arr[sprites->count].type = type;
}

void	free_bonus_struct(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < NB_BONUS_TEXTURES)
	{
		if (ctx->tab_tex_bonus[i])
		{
			free(ctx->tab_tex_bonus[i]);
			ctx->tab_tex_bonus[i] = NULL;
		}
		++i;
	}
}
