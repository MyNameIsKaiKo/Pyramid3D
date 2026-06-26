/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:55:26 by ldepenne          #+#    #+#             */
/*   Updated: 2026/06/26 14:28:35 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

static int	check_textures(char *file)
{
	int		fd_map;
	char	*line_map;

	fd_map = open(file, O_RDONLY);
	if (fd_map < 0)
	{
		print_error("Failed to open map");
		return (1);
	}
	line_map = get_next_line(fd_map);
	if (!line_map)
	{
		print_error("Failed read the map");
		close(fd_map);
		return (1);
	}
	printf("%s", line_map);
	close(fd_map);
	return (0);
}

static int	parse_name(char *file)
{
	char	*ext;
	int		size_ext;

	ext = ft_strrchr(file, '.');
	size_ext = ft_strlen(ext);
	if (ft_strncmp(ext, EXT_FILE, size_ext + 1) != 0)
	{
		print_error("Enter a <file_name>.cub");
		return (1);
	}
	return (0);
}

int	parsing(char *file)
{
	if (parse_name(file) > 0)
		return (1);
	if (check_textures(file) > 0)
		return (1);
	return (0);
}
