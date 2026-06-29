/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:55:19 by ldepenne          #+#    #+#             */
/*   Updated: 2026/06/29 11:56:42 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

int	main(int ac, char **av)
{
	t_ctx	ctx;

	if (ac < 2)
	{
		printf("Enter a map.cub in first argument please\n");
		return (0);
	}
	ft_memset(&ctx, 0, sizeof(t_ctx));
	// ctx.textures = malloc(sizeof(t_textures));
	// if (!ctx.textures)
	// {
	// 	print_error("Malloc Failed");
	// 	return (1);
	// }
	ft_memset(ctx.textures, 0, sizeof(t_textures));
	if (parsing(av[1], &ctx) > 0)
	{
		free_ctx(&ctx);
		return (0);
	}
	free_ctx(&ctx);
	return (0);
}
