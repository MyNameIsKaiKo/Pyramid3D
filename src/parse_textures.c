/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:41:53 by ldepenne          #+#    #+#             */
/*   Updated: 2026/06/27 13:13:48 by ldepenne         ###   ########.fr       */
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

static int parse_textures(char *line_read, t_textures *textures)
{
	int var_return;

	var_return = 0;
	if (ft_strncmp(line_read, "NO ", 3) == 0)
		var_return = init_texture(line_read, &textures->NO_texture);
	if (ft_strncmp(line_read, "SO ", 3) == 0)
		var_return = init_texture(line_read, &textures->SO_texture);
	if (ft_strncmp(line_read, "WE ", 3) == 0)
		var_return = init_texture(line_read, &textures->WE_texture);
	if (ft_strncmp(line_read, "EA ", 3) == 0)
		var_return = init_texture(line_read, &textures->EA_texture);
	if (ft_strncmp(line_read, "F ", 2) == 0)
		var_return = init_texture(line_read, &textures->F_color);
	if (ft_strncmp(line_read, "C ", 2) == 0)
		var_return = init_texture(line_read, &textures->C_color);
	return (var_return);
}

/** @brief read map and extract textures to t_textures*/
void extract_textures(char *file, t_textures *textures)
{
	int fd_map;
	char *line_read;

	fd_map = open(file, O_RDONLY);
	if (fd_map < 0)
	{
		print_error("Failed to open map");
		return;
	}
	line_read = get_next_line(fd_map);
	if (!line_read)
	{
		print_error("Failed read the map");
		close(fd_map);
		return;
	}
	while (line_read)
	{
		parse_textures(line_read, textures);
		free(line_read);
		line_read = get_next_line(fd_map); /** @todo stop if read the map */
	}
	close(fd_map);
	get_next_line(fd_map);
}
