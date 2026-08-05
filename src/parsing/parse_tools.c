/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 10:09:17 by jleray            #+#    #+#             */
/*   Updated: 2026/08/05 10:09:17 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_valid_c(char c)
{
	if (c == WALL || c == FLOOR || isplayer(c))
		return (0);
	if (BONUS && (c == MOINE || c == PIRATE || c == LUTIN || c == DOOR6))
		return (0);
	if (BONUS && (c == WALL2 || c == WALL3 || c == WALL4 || c == WALL5))
		return (0);
	return (1);
}
