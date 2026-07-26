/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:44:54 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/26 15:54:28 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	copy_map(t_map **map)
{
	int	i;
	int	len_nline;

	i = 0;
	(*map)->map_tab = malloc(sizeof(char *) * (*map)->y);
	if (!(*map)->map_tab)
		return (print_error("Malloc failed"));
	while (i < (*map)->y)
	{
		(*map)->map_tab[i] = ft_calloc(sizeof(char), (*map)->x + 1);
		if (!(*map)->map_tab[i])
			return (print_error("Calloc failed"));
		len_nline = ft_strlen((*map)->parse_map[i]);
		(*map)->map_tab[i] = ft_memcpy((*map)->map_tab[i],
				(*map)->parse_map[i], len_nline + 1);
		while (len_nline < (*map)->x)
		{
			(*map)->map_tab[i][len_nline] = ' ';
			len_nline++;
			(*map)->map_tab[i][len_nline] = '\0';
		}
		i++;
	}
	free_parse_map(*map);
	return (0);
}
