/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 10:09:17 by jleray            #+#    #+#             */
/*   Updated: 2026/08/05 11:21:23 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_valid_c(char c)
{
	if (c == WALL || c == FLOOR || isplayer(c))
		return (0);
	if (BONUS && (c == MOINE || c == PIRATE || c == LUTIN || c == DOOR6))
		return (0);
	if (BONUS && iswall(c))
		return (0);
	return (1);
}
