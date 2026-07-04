/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 13:49:55 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/04 15:15:49 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

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

static void	read_map(char *file, t_ctx *ctx)
{
	int		fd_map;
	char	*line_read;

	fd_map = open(file, O_RDONLY);
	line_read = get_next_line(fd_map);
	if (!line_read)
	{
		print_error("Failed read the map");
		close(fd_map);
		free(ctx);
		return ;
	}
	while (line_read)
	{
		if (parse_line(line_read, ctx) > 0)
			break ;
		free(line_read);
		line_read = get_next_line(fd_map);
	}
	if (line_read)
		free(line_read);
	close(fd_map);
	get_next_line(fd_map);
}

static int	parse_name(char *file)
{
	char	*ext;
	int		size_ext;

	ext = ft_strrchr(file, '.');
	if (!ext)
	{
		print_error("Enter a <file_name>.cub");
		return (1);
	}
	size_ext = ft_strlen(ext);
	if (ft_strncmp(ext, EXT_FILE, size_ext + 1) != 0)
	{
		print_error("Enter a <file_name>.cub");
		return (1);
	}
	return (0);
}

int	parsing(char *file, t_ctx *ctx)
{
	if (parse_name(file) > 0)
		return (1);
	read_map(file, ctx);
	parse_path(ctx->textures);
	parse_color(ctx->textures);
	// retrieve_map(file, ctx)
	return (0);
}
