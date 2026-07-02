/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:55:26 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/02 14:27:50 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

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

// static int	parse_line(char *line_read, t_ctx *ctx)
// {
// 	if (ft_strlen(line_read) <= 1 && ctx->start_check_map == false)
// 		return (0);
// 	if (ctx->nb_textures <= NB_ALL_TEXTURES && ctx->start_check_map == false)
// 	{
// 		if (parse_textures(line_read, ctx) > 0)
// 		{
// 			print_error("Textures are incorrect");
// 			return (1);
// 		}
// 		else if (parse_textures(line_read, ctx) < 0)

// 		ctx->nb_textures++;
// 	}
// 	else
// 	{
// 		ctx->map->height++;
// 		if (parse_map(line_read, ctx->map) > 0)
// 		{
// 			free_ctx(ctx);
// 			print_error("Map is incorrect");
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

static int init_texture(char *line_read, char **this_textures, int start)
{
	if (*this_textures)
		return (1);
	*this_textures = ft_substr(line_read, start, strlen(line_read) - (start + 1));
	if (!*this_textures)
	{
		print_error("Malloc failed");
		return (1);
	}
	return (0);
}

static int	parse_line(char *line_read, t_ctx *ctx)
{
	int	value;

	printf("line_read: %s\n", line_read);
	value = 2;
	if (ft_strncmp(line_read, "NO ", 3) == 0 && ctx->start_check_map == false)
		value = init_texture(line_read, &ctx->textures[NO_WALL], 3);
	if (ft_strncmp(line_read, "SO ", 3) == 0 && ctx->start_check_map == false)
		value = init_texture(line_read, &ctx->textures[SO_WALL], 3);
	if (ft_strncmp(line_read, "WE ", 3) == 0 && ctx->start_check_map == false)
		value = init_texture(line_read, &ctx->textures[WE_WALL], 3);
	if (ft_strncmp(line_read, "EA ", 3) == 0 && ctx->start_check_map == false)
		value = init_texture(line_read, &ctx->textures[EA_WALL], 3);
	if (ft_strncmp(line_read, "F ", 2) == 0 && ctx->start_check_map == false)
		value = init_texture(line_read, &ctx->textures[FLOOR_COLOR], 2);
	if (ft_strncmp(line_read, "C ", 2) == 0 && ctx->start_check_map == false)
		value = init_texture(line_read, &ctx->textures[CEILING_COLOR], 2);
	if (ft_strlen(line_read) <= 1 && ctx->start_check_map == false)
		value = 0;
	if (value == 2)
	{
		ctx->start_check_map = true;
		if (parse_map(line_read, ctx->map) > 0)
		{
			free_ctx(ctx);
			print_error("Map is incorrect");
			return (1);
		}
		ctx->map->height++;
	}
	return (value);
}

static void	extract_map(char *file, t_ctx *ctx)
{
	int		fd_map;
	char	*line_read;

	fd_map = open(file, O_RDONLY);
	line_read = get_next_line(fd_map);
	if (!line_read)
	{
		print_error("Failed read the map");
		close(fd_map);
		return;
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

int	parsing(char *file, t_ctx *ctx)
{
	if (parse_name(file) > 0)
		return (1);
	extract_map(file, ctx);
	return (0);
}
