/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:55:19 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/02 13:44:51 by ldepenne         ###   ########.fr       */
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
	ft_memset(ctx.textures, 0, sizeof(t_textures));
	ctx.map = malloc(sizeof(t_map));
	if (!ctx.map)
	{
		free_ctx(&ctx);
		return (1);
	}
	ft_memset(ctx.map, 0 , sizeof(t_map));
	if (parsing(av[1], &ctx) > 0)
	{
		free_ctx(&ctx);
		return (0);
	}
	int i = 0;
	while (ctx.map->tab_map[i])
	{
		int j = 0;
		while (ctx.map->tab_map[i][j])
		{
			printf("%d\n", ctx.map->tab_map[i][j]);
			j++;
		}
		i++;
	}
	free_ctx(&ctx);
	return (0);
}
