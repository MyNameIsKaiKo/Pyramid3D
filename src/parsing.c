/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:55:26 by ldepenne          #+#    #+#             */
/*   Updated: 2026/06/29 11:55:08 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

static int	check_textures(char *file, t_ctx *ctx)
{
	int	i;

	extract_textures(file, ctx);
	i = 0;
	while (ctx->textures[i] != NULL)
		i++;
	if (i < NB_TEXTURES)
	{
		print_error("Not all textures are accessible");
		return (1);
	}
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
	if (check_textures(file, ctx) > 0)
		return (1);
	//check map
	return (0);
}
