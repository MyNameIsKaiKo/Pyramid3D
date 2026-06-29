/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:26:28 by ldepenne          #+#    #+#             */
/*   Updated: 2026/06/29 11:42:13 by ldepenne         ###   ########.fr       */
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
	size_t	i;

	i = 0;
	while (i < NB_TEXTURES)
	{
		free(ctx->textures[i]);
		++i;
	}
}
