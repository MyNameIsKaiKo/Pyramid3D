/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_bhook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:35:20 by jleray            #+#    #+#             */
/*   Updated: 2026/06/25 19:35:20 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pyramid_mlx.h"

static int	shoot(int button, int x, int y, t_map *map)
{
	if (button == 1)
		ft_putstr_fd("SHOOT", 1);
	if (button == 2)
		ft_putstr_fd("SHOW MAP", 1);
	return (1);
}

int	undlebutton(int button, int x, int y, t_map *map)
{
	if (button == 1 || button == 2)
		shoot(button, x, y, map);
	return (0);
}
