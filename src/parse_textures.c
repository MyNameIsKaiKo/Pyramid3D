/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:41:53 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/02 14:11:44 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

static int	valid_color(char **tab_color)
{
	int		check_color;
	int		i;

	i = 0;
	while (tab_color[i])
	{
		check_color = ft_atoi(tab_color[i]);
		if (check_color < 0 || check_color > 255)
		{
			print_error("Color is invalid");
			return (1);
		}
		i++;
	}
	if (i != 3)
	{
		print_error("Color is invalid");
		return (1);
	}
	return (0);
}

int	parse_color(char **color)
{
	char	**tab_color;
	int		index_color;

	index_color = NB_PATH_TEXTURES;
	while (index_color < NB_ALL_TEXTURES)
	{
		tab_color = ft_split(color[index_color], ',');
		if (!tab_color)
		{
			print_error("Malloc failed");
			return (1);
		}
		if (valid_color(tab_color) > 0)
		{
			free_matrix(tab_color);
			return (1);
		}
		index_color++;
		free_matrix(tab_color);
	}
	return (0);
}

int	parse_path(char **textures)
{
	int	i;
	int fd;

	i = 0;
	while (i < NB_PATH_TEXTURES)
	{
		fd = open(textures[i], O_RDONLY);
		if (fd < 0)
		{
			print_error("A texture is inaccessible");
			return (1);
		}
		i++;
		close(fd);
	}
	return (0);
}

// static int init_texture(char *line_read, char **this_textures, int start)
// {
// 	if (*this_textures)
// 		return (1);
// 	*this_textures = ft_substr(line_read, start, strlen(line_read) - (start + 1));
// 	if (!*this_textures)
// 	{
// 		print_error("Malloc failed");
// 		return (1);
// 	}
// 	return (0);
// }

// int parse_textures(char *line_read, t_ctx *ctx)
// {
// 	int	var_return;

// 	var_return = 2;
// 	if (ft_strncmp(line_read, "NO ", 3) == 0)
// 		var_return = init_texture(line_read, &ctx->textures[NO_WALL], 3);
// 	if (ft_strncmp(line_read, "SO ", 3) == 0)
// 		var_return = init_texture(line_read, &ctx->textures[SO_WALL], 3);
// 	if (ft_strncmp(line_read, "WE ", 3) == 0)
// 		var_return = init_texture(line_read, &ctx->textures[WE_WALL], 3);
// 	if (ft_strncmp(line_read, "EA ", 3) == 0)
// 		var_return = init_texture(line_read, &ctx->textures[EA_WALL], 3);
// 	if (ft_strncmp(line_read, "F ", 2) == 0)
// 		var_return = init_texture(line_read, &ctx->textures[FLOOR_COLOR], 2);
// 	if (ft_strncmp(line_read, "C ", 2) == 0)
// 		var_return = init_texture(line_read, &ctx->textures[CEILING_COLOR], 2);
// 	if (var_return == 2)
// 	{
// 		ctx->start_check_map = true;
// 		var_return = -1;
// 	}
// 	return (var_return);
// }
