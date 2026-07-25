/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_tex_sprite_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 18:27:20 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/25 17:19:16 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	parse_sprite_path(char *path_sprite)
{
	int	fd;

	fd = open(path_sprite, O_RDONLY);
	if (fd < 0)
		return (print_error("A sprite texture is inaccessible"));
	close(fd);
	return (0);
}

static int	lutin_sprite(char **tab, t_ctx *ctx)
{
	int	i;
	int	id;

	i = 1;
	id = 0;
	while (i < MAXLFRAME + 1)
	{
		ctx->sprites.lutin_p[id] = ft_strdup(tab[i]);
		if (!ctx->sprites.lutin_p[id])
			return (print_error("ft_strdup failed"));
		if (parse_sprite_path(ctx->sprites.lutin_p[id]) > 0)
			return (1);
		i++;
		id++;
	}
	return (0);
}

static int	moine_sprite(char **tab, t_ctx *ctx)
{
	int	i;
	int	id;

	i = 1;
	id = 0;
	while (i < MAXMFRAME + 1)
	{
		ctx->sprites.moine_p[id] = ft_strdup(tab[i]);
		if (!ctx->sprites.moine_p[id])
			return (print_error("ft_strdup failed"));
		if (parse_sprite_path(ctx->sprites.moine_p[id]) > 0)
			return (1);
		i++;
		id++;
	}
	return (0);
}

static int	pirate_sprite(char **tab, t_ctx *ctx)
{
	int	i;
	int	id;

	i = 1;
	id = 0;
	while (i < MAXPFRAME + 1)
	{
		ctx->sprites.pirate_p[id] = ft_strdup(tab[i]);
		if (!ctx->sprites.pirate_p[id])
			return (print_error("ft_strdup failed"));
		if (parse_sprite_path(ctx->sprites.pirate_p[id]) > 0)
			return (1);
		i++;
		id++;
	}
	return (0);
}

int	sprite_recover(char *line, t_ctx *ctx)
{
	char	**split;
	int		i;
	int		j;

	split = ft_split(line, ' ');
	if (!split)
		return (print_error("Malloc failed"));
	i = 0;
	while (split[i])
	{
		j = ft_strlen(split[i]) - 1;
		if (split[i][j] == '\n')
			split[i][j] = '\0';
		i++;
	}
	if (split[0][0] == 'L')
	{
		if (lutin_sprite(split, ctx) > 0)
		{
			free_matrix(split);
			return (1);
		}
	}
	if (split[0][0] == 'M')
		if (moine_sprite(split, ctx) > 0)
		{
			free_matrix(split);
			return (1);
		}
	if (split[0][0] == 'P')
		if (pirate_sprite(split, ctx) > 0)
		{
			free_matrix(split);
			return (1);
		}
	free_matrix(split);
	return (0);
}
