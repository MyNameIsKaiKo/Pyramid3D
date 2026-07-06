/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:26:28 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/06 20:06:23 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

int	print_error(char *err_msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(err_msg, 2);
	return (1);
}

void	free_ctx(t_ctx *ctx)
{
	size_t	i;

	i = 0;
	while (i < NB_ALL_TEXTURES)
	{
		if (ctx->textures[i])
		{
			free(ctx->textures[i]);
			ctx->textures[i] = NULL;
		}
		++i;
	}
	size_t j = 0;
	while (j < ctx->map->height)
	{
		free(ctx->map->tab_map[j]);
		ctx->map->tab_map[j] = NULL;
		j++;
	}
	free(ctx->map->tab_map);
	free(ctx->map);
}
