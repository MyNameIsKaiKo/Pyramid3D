/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:55:19 by ldepenne          #+#    #+#             */
/*   Updated: 2026/06/25 19:36:49 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Enter a map.cub in first argument please\n");
		return (0);
	}
	if (parsing(av[1]) > 0)
		return (0);
	return (0);
}
