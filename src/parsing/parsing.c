/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 13:49:55 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/20 22:03:51 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	parse_line(char *line_read, t_ctx *ctx)
{
	if (ctx->n_textures < NB_ALL_TEXTURES)
	{
		if (ft_strncmp(line_read, "\n", 2) == 0)
			return (0);
		if (parse_textures(line_read, ctx) > 0)
			return (1);
	}
	else
	{
		if (check_line_map(line_read, ctx->map) > 0)
			return (1);
	}
	return (0);
}

static int	read_line(t_ctx *ctx, int fd_map)
{
	char	*line_read;

	line_read = get_next_line(fd_map);
	if (!line_read)
	{
		print_error("Failed read the map");
		return (1);
	}
	while (line_read)
	{
		if (parse_line(line_read, ctx) > 0)
		{
			free(line_read);
			return (1);
		}
		free(line_read);
		line_read = get_next_line(fd_map);
	}
	free(line_read);
	return (0);
}

static int	read_map(char *file, t_ctx *ctx)
{
	int	fd_map;
	int	result;

	fd_map = open(file, O_RDONLY);
	if (fd_map < 0)
	{
		print_error("Failed read the map");
		return (1);
	}
	result = read_line(ctx, fd_map);
	close(fd_map);
	get_next_line(fd_map);
	return (result);
}

int	parse_extention(char *file, char *extention)
{
	char	*ext_file;
	int		size_ext;

	ext_file = ft_strrchr(file, '.');
	if (!ext_file)
		return (print_error("bad extention (.cub or .xpm)"));
	size_ext = ft_strlen(ext_file);
	if (ft_strncmp(ext_file, extention, size_ext + 1) != 0)
		return (print_error("bad extention (.cub or .xpm)"));
	return (0);
}

int	parsing(char *file, t_ctx *ctx)
{
	if (parse_extention(file, EXT_FILE) > 0)
		return (1);
	if (read_map(file, ctx) > 0)
		return (1);
	if (parse_path(ctx->tab_textures) > 0)
		return (1);
	if (!BONUS && parse_color(ctx->tab_textures) > 0)
		return (1);
	if (BONUS && parse_color_bonus(ctx->tab_textures) > 0)
		return (1);
	if (parse_map(ctx->map) > 0)
		return (1);
	if (ctx->map->nb_player != 1)
		return (print_error("The number of player is incorrect"));
	if (copy_map(&ctx->map) > 0)
		return (1);
	return (0);
}
