/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:26:28 by ldepenne          #+#    #+#             */
/*   Updated: 2026/06/26 23:27:41 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

void print_error(char *err_msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(err_msg, 2);
}

void free_ctx(t_ctx *ctx)
{
	if (ctx->textures.NO_texture)
		free(ctx->textures.NO_texture);
	free(ctx->textures.SO_texture);
	free(ctx->textures.WE_texture);
	free(ctx->textures.EA_texture);
	free(ctx->textures.F_color);
	free(ctx->textures.C_color);
}
