/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 13:54:23 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/07 13:44:37 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

int	parse_path(char **textures)
{
	int	i;
	int	fd;

	i = 0;
	while (i < NB_TEXTURES)
	{
		fd = open(textures[i], O_RDONLY);
		if (fd < 0)
			return (print_error("A texture is inaccessible"));
		i++;
		close(fd);
	}
	return (0);
}

static int	init_texture(char *line_read, char **ctx_texture, t_ctx *ctx)
{
	size_t	len;

	if (*ctx_texture)
		return (1);
	len = strlen(line_read);
	if (line_read[len - 1] == '\n')
	{
		line_read[len - 1] = '\0';
		--len;
	}
	*ctx_texture = ft_substr(line_read, 0, len);
	if (!*ctx_texture)
		return (print_error("Malloc failed"));
	ctx->n_textures++;
	return (0);
}

static int	is_texture(char *line_read, t_ctx *ctx, int i)
{
	int					len;
	int					i_tab;
	char				**ctx_textures;
	const t_tex_mgnt	tab[] = {{"NO ", NO_WALL}, {"SO ", SO_WALL},
	{"WE ", WE_WALL}, {"EA ", EA_WALL}, {"F ", FLOOR_COLOR},
	{"C ", CEILING_COLOR}};

	i_tab = -1;
	while (++i_tab < NB_ALL_TEXTURES)
	{
		len = ft_strlen(tab[i_tab].cmp);
		if (ft_strncmp(line_read + i, tab[i_tab].cmp, len) == 0)
		{
			i += ft_strlen(tab[i].cmp);
			ctx_textures = &ctx->textures[tab[i_tab].textures];
			if (init_texture(line_read + i, ctx_textures, ctx) > 0)
				return (1);
			break ;
		}
	}
	if (i_tab >= NB_ALL_TEXTURES)
		return (print_error("Incorrect texture"));
	return (0);
}

int	parse_textures(char *line_read, t_ctx *ctx)
{
	int	i;

	i = 0;
	while (line_read[i] && !ft_isalnum(line_read[i]))
		i++;
	if (is_texture(line_read, ctx, i) > 0)
		return (1);
	return (0);
}
