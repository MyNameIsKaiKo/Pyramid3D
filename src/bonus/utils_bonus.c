/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:31:33 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/22 09:32:01 by ldepenne         ###   ########.fr       */
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
