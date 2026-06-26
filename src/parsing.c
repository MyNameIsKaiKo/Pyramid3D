/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:55:26 by ldepenne          #+#    #+#             */
/*   Updated: 2026/06/26 23:27:29 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

static int	check_textures(char *file, t_textures *textures)
{
	extract_textures(file, textures);
	printf("NO: %s\n", textures->NO_texture);
	printf("SO: %s\n", textures->SO_texture);
	printf("WE: %s\n", textures->WE_texture);
	printf("EA: %s\n", textures->EA_texture);
	printf("F: %s\n", textures->F_color);
	printf("C: %s\n", textures->C_color);
	//review, est ce que j'ai tout
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

int	parsing(char *file, t_ctx *ctx)
{
	if (parse_name(file) > 0)
		return (1);
	if (check_textures(file, &ctx->textures) > 0)
		return (1);
	//check map
	return (0);
}
