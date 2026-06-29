/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:41:53 by ldepenne          #+#    #+#             */
/*   Updated: 2026/06/29 11:31:39 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

static int init_texture(char *line_read, char **this_textures)
{
	if (*this_textures)
	{
		print_error("a texture is duplicated");
		return (1);
	}
	*this_textures = ft_strdup(line_read);
	if (!*this_textures)
		return (1);
	return (0);
}

static int parse_textures(char *line_read, t_ctx *ctx)
{
	int	var_return;

	var_return = 1;
	if (ft_strncmp(line_read, "NO ", 3) == 0)
		var_return = init_texture(line_read, &ctx->textures[NO]);
	if (ft_strncmp(line_read, "SO ", 3) == 0)
		var_return = init_texture(line_read, &ctx->textures[SO]);
	if (ft_strncmp(line_read, "WE ", 3) == 0)
		var_return = init_texture(line_read, &ctx->textures[WE]);
	if (ft_strncmp(line_read, "EA ", 3) == 0)
		var_return = init_texture(line_read, &ctx->textures[EA]);
	if (ft_strncmp(line_read, "F ", 2) == 0)
		var_return = init_texture(line_read, &ctx->textures[F]);
	if (ft_strncmp(line_read, "C ", 2) == 0)
		var_return = init_texture(line_read, &ctx->textures[C]);
	if (ft_strlen(line_read) <= 1)
		var_return = 0;
	return (var_return);
}

/** @brief read map and extract textures to t_textures*/
void extract_textures(char *file, t_ctx *ctx)
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
		if (parse_textures(line_read, ctx) > 0)
		{
			free(line_read);
			break ;
		}
		free(line_read);
		line_read = get_next_line(fd_map);
	}
	close(fd_map);
	get_next_line(fd_map);
}
