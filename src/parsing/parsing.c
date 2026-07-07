/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 13:49:55 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/07 22:20:07 by ldepenne         ###   ########.fr       */
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
		{
			free_ctx(ctx);
			return (1);
		}
	}
	else
	{
		if (check_line_map(line_read, ctx->map) > 0)
		{
			free_ctx(ctx);
			return (1);
		}
	}
	return (0);
}

static int	read_map(char *file, t_ctx *ctx)
{
	int		fd_map;
	int		var_return;
	char	*line_read;

	fd_map = open(file, O_RDONLY);
	line_read = get_next_line(fd_map);
	if (!line_read)
	{
		print_error("Failed read the map");
		close(fd_map);
		free(ctx);
		return (1);
	}
	while (line_read)
	{
		var_return = parse_line(line_read, ctx);
		if (var_return > 0)
			break ;
		free(line_read);
		line_read = get_next_line(fd_map);
	}
	free(line_read);
	close(fd_map);
	get_next_line(fd_map);
	return (var_return);
}

static int	parse_name(char *file)
{
	char	*ext;
	int		size_ext;

	ext = ft_strrchr(file, '.');
	if (!ext)
		return (print_error("Enter a <file_name>.cub"));
	size_ext = ft_strlen(ext);
	if (ft_strncmp(ext, EXT_FILE, size_ext + 1) != 0)
		return (print_error("Enter a <file_name>.cub"));
	return (0);
}

int	parsing(char *file, t_ctx *ctx)
{
	if (parse_name(file) > 0)
		return (1);
	if (read_map(file, ctx) > 0)
		return (1);
	if (parse_path(ctx->tab_textures) > 0)
		return (1);
	if (parse_color(ctx->tab_textures) > 0)
		return (1);
	if (parse_map(ctx->map) > 0)
		return (1);
	return (0);
}
