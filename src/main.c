/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:55:19 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/04 15:36:41 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

static int	set_struct(t_ctx *ctx)
{
	ft_memset(ctx, 0, sizeof(t_ctx));
	ctx->map = malloc(sizeof(t_map));
	if (!ctx->map)
	{
		print_error("Malloc failed");
		free_ctx(ctx);
		return (1);
	}
	ft_memset(ctx->map, 0, sizeof(t_map));
	return (0);
}

int	main(int ac, char **av)
{
	t_ctx	ctx;

	if (ac < 2)
	{
		printf("Enter a map.cub in first argument please\n");
		return (0);
	}
	if (set_struct(&ctx) > 0)
		return (1);
	if (parsing(av[1], &ctx) > 0)
		return (1);
	free_ctx(&ctx);
	return (0);
}
