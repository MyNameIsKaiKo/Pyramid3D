/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   falsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 01:07:05 by jleray            #+#    #+#             */
/*   Updated: 2026/06/27 01:07:05 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pyramid_mlx.h"

void	fill_fmap(t_map *map)
{
	int	i;

	i = 0;
	map->map_tab = malloc(sizeof(char *) * 11);
	map->map_tab[0] = ft_strdup("1111111111");
	map->map_tab[1] = ft_strdup("1000000001");
	map->map_tab[2] = ft_strdup("1000011001");
	map->map_tab[3] = ft_strdup("1000011001");
	map->map_tab[4] = ft_strdup("1001111001");
	map->map_tab[5] = ft_strdup("1001100001");
	map->map_tab[6] = ft_strdup("1001111001");
	map->map_tab[7] = ft_strdup("1000011111");
	map->map_tab[8] = ft_strdup("1000000001");
	map->map_tab[9] = ft_strdup("1111111111");
	map->map_tab[10] = ft_strdup("\0");
	map->starting_coord.x = 5.5;
	map->starting_coord.y = 8.5;
	map->width = 10;
	map->height = 10;
	return ;
}
