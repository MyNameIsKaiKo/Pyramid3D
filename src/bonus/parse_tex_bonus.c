/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 17:10:56 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/24 18:54:24 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parse_path_bonus(char **textures)
{
	int	i;
	int	fd;

	i = 0;
	while (i < NB_BONUS_TEXTURES)
	{
		fd = open(textures[i], O_RDONLY);
		if (fd < 0)
			return (print_error("A texture is inaccessible"));
		i++;
		close(fd);
	}
	return (0);
}

static int	init_texture(char *line_read, char **tex, t_ctx *ctx, char *type)
{
	size_t	len;

	if (*tex)
		return (1);
	len = ft_strlen(type) + 1;
	if (ft_strncmp(type, "LUTIN", len) == 0 || ft_strncmp(type, "MOINE", len) == 0 || ft_strncmp(type, "PIRATE", len) == 0)
	{
		if (sprite_recover(line_read, ctx) > 0)
			return (1);
		ctx->n_textures++;
		return (0);
	}
	line_read += ft_strcharlen(line_read, ' ');
	len = ft_strlen(line_read);
	if (line_read[len - 1] == '\n')
	{
		line_read[len - 1] = '\0';
		--len;
	}
	*tex = ft_substr(line_read, 0, len);
	if (!*tex)
		return (print_error("Malloc failed"));
	ctx->n_textures++;
	return (0);
}

static int	is_texture(char *line_read, t_ctx *ctx, int i)
{
	int						len;
	int						i_tab;
	char					**ctx_textures;
	const t_tex_mgnt_bonus	tab[] = {{"NO ", B_NO_WALL}, {"SO ", B_SO_WALL},
	{"WE ", B_WE_WALL}, {"EA ", B_EA_WALL}, {"L ", B_L_LUTIN}, {"M ",
		B_M_MOINE}, {"P ", B_P_PIRATE}, {"F ", B_F_FLOOR_COLOR}, {"C ", B_C_CEILING_COLOR}};

	i_tab = -1;
	while (++i_tab < NB_BONUS_TEXTURES)
	{
		len = ft_strlen(tab[i_tab].cmp);
		if (ft_strncmp(line_read + i, tab[i_tab].cmp, len) == 0)
		{
			i += ft_strlen(tab[i].cmp);
			ctx_textures = &ctx->tab_tex_bonus[tab[i_tab].textures];
			if (init_texture(line_read, ctx_textures, ctx, tab[i_tab].cmp) > 0)
				return (1);
			if (parse_extention(line_read, EXT_TEXT) > 0)
				return (1);
			break ;
		}
	}
	if (i_tab >= NB_BONUS_TEXTURES)
		return (print_error("Incorrect texture"));
	return (0);
}

int	parse_tex_bonus(char *line_read, t_ctx *ctx)
{
	int	i;

	i = 0;
	while (line_read[i] && !ft_isalnum(line_read[i]))
		i++;
	if (is_texture(line_read, ctx, i) > 0)
		return (1);
	return (0);
}
