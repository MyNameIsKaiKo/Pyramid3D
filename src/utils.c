/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:26:28 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/27 11:39:57 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	data_player(t_map *map, size_t y, size_t x)
{
	map->starting_coord.x = (double)x + 0.5;
	map->starting_coord.y = (double)y + 0.5;
	map->p_orient = map->parse_map[y][x];
	map->nb_player++;
	map->parse_map[y][x] = FLOOR;
}

int	print_error(const char *err_msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(err_msg, 2);
	return (1);
}

int	isplayer(char c)
{
	if (c == N_PLAYER || c == E_PLAYER
		|| c == S_PLAYER || c == W_PLAYER)
		return (1);
	return (0);
}

/** @brief return number of char before char c, c include*/
size_t	ft_strcharlen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	while (s[i] && s[i] == c)
		i++;
	return (i);
}
