/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 01:48:50 by jleray            #+#    #+#             */
/*   Updated: 2026/07/26 21:16:11 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	free_sprite_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		if (paths[i])
			free(paths[i]);
		paths[i] = NULL;
		i++;
	}
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
	free_sprite_paths(ctx->sprites.lutin_p);
	free_sprite_paths(ctx->sprites.moine_p);
	free_sprite_paths(ctx->sprites.lutin_p);
}
