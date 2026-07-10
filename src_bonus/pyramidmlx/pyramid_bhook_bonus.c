/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_bhook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:35:20 by jleray            #+#    #+#             */
/*   Updated: 2026/07/10 13:29:13 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static int	shoot(int button, int x, int y, t_map *map)
{
	(void)map;
	(void)x;
	(void)y;
	if (button == 1)
		ft_putstr_fd("SHOOT", 1);
	if (button == 2)
		ft_putstr_fd("SHOW MAP", 1);
	return (1);
}

int	handlebutton(int button, int x, int y, void *map)
{
	if (button == 1 || button == 2)
		shoot(button, x, y, map);
	return (0);
}
