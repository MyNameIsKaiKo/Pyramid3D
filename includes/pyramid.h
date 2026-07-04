/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 13:23:52 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/04 14:54:27 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PYRAMID_H
# define PYRAMID_H

# include "libft/include/libft.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

# define EXT_FILE ".cub"
# define NB_COLOR 2
# define NB_TEXTURES 4
# define NB_ALL_TEXTURES 6

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

typedef enum e_tile_type
{
	FLOOR,
	WALL,
	EMPTY,
	PLAYER
}	t_tile_type;

typedef struct s_mgmnt_tex
{
	char		*cmp;
	t_textures	textures;
}	t_mgmnt_tex;

typedef struct s_vec2
{
	size_t	x;
	size_t	y;
}	t_vec2;

typedef struct s_map
{
	t_tile_type	**tab_map;
	size_t		height;
	size_t		width;
	t_vec2		p_pos;
	char		p_orient;
}	t_map;

typedef struct s_ctx
{
	char	*textures[NB_ALL_TEXTURES];
	t_map	*map;
	size_t	n_textures;
}	t_ctx;

//utils.c
void	print_error(char *err_msg);
void	free_ctx(t_ctx *ctx);

//parsing.c
int		parsing(char *file, t_ctx *ctx);

//parse_textures.c
int		parse_path(char **textures);
int		parse_textures(char *line_read, t_ctx *ctx);

//parse_color.c
int		parse_color(char **color);

//parse_map.c
int		check_line_map(char *line_read, t_map *map);

#endif