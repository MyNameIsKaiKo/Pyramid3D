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
	t_map map;

	ft_memset(&map, 0, sizeof(t_map));
	printf("\n 1 - Je suis la \n");
	fill_fmap(&map);
	printf("\n 2 - Je suis la \n");
	player_init(&map);
	printf("\n 3 - Je suis la \n");
	pyramid_loop(&map);
	printf("\n 4 - Je suis la \n");
	return (0);
}
