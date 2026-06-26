/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:41:53 by ldepenne          #+#    #+#             */
/*   Updated: 2026/06/26 23:09:08 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

static void	parse_textures(char *line_read, t_textures *textures)
{
	if (ft_strncmp(line_read, "NO ", 3) == 0)
	{
		if (!textures->NO_texture)
		{
			textures->NO_texture = malloc(sizeof(char) * ft_strlen(line_read));
			if (!textures->NO_texture)
			{
				print_error("Malloc failed");
				return ;
			}
			textures->NO_texture = ft_strdup(line_read);
		}
		else
			return ; /** @todo return info i have a double */
	}
	if (ft_strncmp(line_read, "SO ", 3) == 0)
		textures->SO_texture = ft_strdup(line_read);
	if (ft_strncmp(line_read, "WE ", 3) == 0)
		textures->WE_texture = ft_strdup(line_read);
	if (ft_strncmp(line_read, "EA ", 3) == 0)
		textures->EA_texture = ft_strdup(line_read);
	if (ft_strncmp(line_read, "F ", 2) == 0)
		textures->F_color = ft_strdup(line_read);
	if (ft_strncmp(line_read, "C ", 2) == 0)
		textures->C_color = ft_strdup(line_read);
}

/** @brief read map and extract textures to t_textures*/
void	extract_textures(char *file, t_textures *textures)
{
	int		fd_map;
	char	*line_read;

	fd_map = open(file, O_RDONLY);
	if (fd_map < 0)
	{
		print_error("Failed to open map");
		return ;
	}
	line_read = get_next_line(fd_map);
	if (!line_read)
	{
		print_error("Failed read the map");
		close(fd_map);
		return ;
	}
	parse_textures(line_read, textures);
	free(line_read);
	close(fd_map);
	get_next_line(fd_map);
}
