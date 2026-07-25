/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 12:07:27 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/25 15:40:35 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	parse_line_bonus(char *line_read, t_ctx *ctx)
{
	if (ctx->n_textures < NB_BONUS_TEXTURES)
	{
		if (ft_strcmp(line_read, "\n") == 0)
			return (0);
		else if (parse_tex_bonus(line_read, ctx) > 0)
			return (1);
	}
	else
	{
		if (check_line_map(line_read, ctx->map) > 0)
			return (1);
	}
	return (0);
}

static int	read_line_bonus(t_ctx *ctx, int fd_map)
{
	char	*line_read;

	line_read = get_next_line(fd_map);
	if (!line_read)
	{
		print_error("Failed read the map");
		return (1);
	}
	while (line_read)
	{
		if (parse_line_bonus(line_read, ctx) > 0)
		{
			free(line_read);
			return (1);
		}
		free(line_read);
		line_read = get_next_line(fd_map);
	}
	free(line_read);
	return (0);
}

static int	recover_file_bonus(char *file, t_ctx *ctx)
{
	int	fd_map;
	int	result;

	fd_map = open(file, O_RDONLY);
	if (fd_map < 0)
	{
		print_error("Failed read the map");
		return (1);
	}
	result = read_line_bonus(ctx, fd_map);
	close(fd_map);
	get_next_line(fd_map);
	return (result);
}

int	parsing_bonus(char *file, t_ctx *ctx)
{
	if (recover_file_bonus(file, ctx) > 0)
		return (1);
	if (parse_path_bonus(ctx->tab_tex_bonus) > 0)
		return (1);
	if (parse_map_bonus(ctx) > 0)
		return (1);
	return (0);
}
