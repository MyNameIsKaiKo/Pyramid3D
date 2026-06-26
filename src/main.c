/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:55:19 by ldepenne          #+#    #+#             */
/*   Updated: 2026/06/26 23:05:12 by ldepenne         ###   ########.fr       */
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
	if (parsing(av[1], &ctx) > 0)
		return (0);
	free_ctx(&ctx);
	return (0);
}
