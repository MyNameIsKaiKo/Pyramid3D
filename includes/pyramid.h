/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:57:08 by ldepenne          #+#    #+#             */
/*   Updated: 2026/06/29 16:30:21 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PYRAMID_H
# define PYRAMID_H

# include "libft/include/libft.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# define EXT_FILE ".cub"
# define NB_COLOR 2
# define NB_PATH_TEXTURES 4
# define NB_ALL_TEXTURES NB_COLOR + NB_PATH_TEXTURES

/** @important Textures with paths must be placed before the RGB colours */
typedef enum e_textures
{
	NO_WALL,
	SO_WALL,
	WE_WALL,
	EA_WALL,
	FLOOR_COLOR,
	CEILING_COLOR
}	t_textures;

typedef struct s_map
{
	char	**tab_map;
	size_t	height;
	size_t	width;
	char	start_pos;
}	t_map;

typedef struct s_ctx
{
	char	*textures[NB_ALL_TEXTURES];
	t_map	*map;
}	t_ctx;

//parsing.c
int		parsing(char *file, t_ctx *ctx);

//parse_textures.c
int		parse_path(char **textures);
void	extract_textures(char *file, t_ctx *ctx);

//parse_color.c
int		parse_color(char **color);

//utils.c
void	print_error(char *err_msg);
void	free_ctx(t_ctx *ctx);

#endif