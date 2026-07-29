/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_weapon_sp_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 10:33:03 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/29 10:33:21 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	weapon_recover(char *line, t_ctx *ctx)
{
	char	**tab;
	int		i;
	int		id;

	tab = ft_split(line, ' ');
	if (!tab)
		return (print_error("Malloc failed"));
	tab[MAXWFRAME] = ft_strtrim(tab[MAXWFRAME], "\n");
	i = 1;
	id = 0;
	while (tab[i] && i < MAXWFRAME + 1)
	{
		ctx->player.weapon_p[id] = ft_strdup(tab[i]);
		if (!ctx->player.weapon_p[id])
			return (print_error("ft_strdup failed"));
		if (parse_sprite_path(ctx->player.weapon_p[id]) > 0)
			return (1);
		i++;
		id++;
	}
	if (i != MAXWFRAME + 1)
		return (print_error("Weapon doesn't have three sprite"));
	free_matrix(tab);
	return (0);
}
