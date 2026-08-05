/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_sprites_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 10:33:03 by ldepenne          #+#    #+#             */
/*   Updated: 2026/08/05 12:03:59 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	lutin_sprite(char **tab, t_ctx *ctx)
{
	int	i;
	int	id;

	i = 1;
	id = 0;
	if (check_nb_frame(tab, MAXLFRAME + 1) > 0)
		return (print_error("Lutin don't have five frames"));
	tab[MAXLFRAME] = ft_strtrim(tab[MAXLFRAME], "\n");
	while (tab[i] && i < MAXLFRAME + 1)
	{
		ctx->sprites.lutin_p[id] = ft_strdup(tab[i]);
		if (!ctx->sprites.lutin_p[id])
			return (print_error("ft_strdup failed"));
		if (parse_sprite_path(ctx->sprites.lutin_p[id]) > 0)
			return (1);
		i++;
		id++;
	}
	if (i != MAXLFRAME + 1)
		return (print_error("Lutin doesn't have five frames"));
	return (0);
}

int	moine_sprite(char **tab, t_ctx *ctx)
{
	int	i;
	int	id;

	i = 1;
	id = 0;
	if (check_nb_frame(tab, MAXMFRAME + 1) > 0)
		return (print_error("Moinu don't have three frames"));
	tab[MAXMFRAME] = ft_strtrim(tab[MAXMFRAME], "\n");
	while (tab[i] && i < MAXMFRAME + 1)
	{
		ctx->sprites.moine_p[id] = ft_strdup(tab[i]);
		if (!ctx->sprites.moine_p[id])
			return (print_error("ft_strdup failed"));
		if (parse_sprite_path(ctx->sprites.moine_p[id]) > 0)
			return (1);
		i++;
		id++;
	}
	if (i != MAXMFRAME + 1)
		return (print_error("Moinu doesn't have three frames"));
	return (0);
}

int	pirate_sprite(char **tab, t_ctx *ctx)
{
	int	i;
	int	id;

	i = 1;
	id = 0;
	if (check_nb_frame(tab, MAXPFRAME + 1) > 0)
		return (print_error("Pirate don't have three frames"));
	tab[MAXPFRAME] = ft_strtrim(tab[MAXPFRAME], "\n");
	while (tab[i] && i < MAXPFRAME + 1)
	{
		ctx->sprites.pirate_p[id] = ft_strdup(tab[i]);
		if (!ctx->sprites.pirate_p[id])
			return (print_error("ft_strdup failed"));
		if (parse_sprite_path(ctx->sprites.pirate_p[id]) > 0)
			return (1);
		i++;
		id++;
	}
	if (i != MAXPFRAME + 1)
		return (print_error("Pirate doesn't have three frames"));
	return (0);
}

static int	weapon_sprite(char **tab, t_ctx *ctx)
{
	int	i;
	int	id;

	i = 1;
	id = 0;
	if (check_nb_frame(tab, MAXWFRAME + 1) > 0)
		return (print_error("Weapon don't have three textures.xpm"));
	tab[MAXWFRAME] = ft_strtrim(tab[MAXWFRAME], "\n");
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
	return (0);
}

int	weapon_recover(char *line, t_ctx *ctx)
{
	char	**tab;
	int		output;

	tab = ft_split(line, ' ');
	if (!tab)
		return (print_error("Malloc failed"));
	output = weapon_sprite(tab, ctx);
	free_matrix(tab);
	return (output);
}
