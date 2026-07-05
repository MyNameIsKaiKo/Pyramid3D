/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 01:20:05 by jleray            #+#    #+#             */
/*   Updated: 2026/07/04 01:20:05 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pyramid_mlx.h"

int	main(void)
{
	t_map	map;

	ft_memset(&map, 0, sizeof(t_map));
	fill_fmap(&map);
	player_init(&map);
	pyramid_loop(&map);
	return (0);
}
