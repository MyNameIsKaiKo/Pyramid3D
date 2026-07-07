/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 13:23:52 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/07 17:18:17 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PYRAMID_H
# define PYRAMID_H

# include "gnl/get_next_line.h"
# include "libft/include/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# ifndef EXT_FILE
#  define EXT_FILE ".cub"
# endif

# define NB_COLOR 2
# define NB_TEXTURES 4
# define NB_ALL_TEXTURES 6

/** @important Textures with paths must be placed before the RGB colours */
typedef enum e_text
{
	NO_WALL,
	SO_WALL,
	WE_WALL,
	EA_WALL,
	FLOOR_COLOR,
	CEILING_COLOR
}	t_textures;

// typedef struct s_jtexures
// {
// 	char	*NO_texture;
// 	char	*SO_texture;
// 	char	*WE_texture;
// 	char	*EA_texture;
// 	char	*F_color;
// 	char	*C_color;
// }	t_jtextures;

typedef enum e_tile_type
{
	FLOOR = '0',
	WALL = '1',
	EMPTY = ' ',
	N_PLAYER = 'N',
	E_PLAYER = 'E',
	S_PLAYER = 'S',
	W_PLAYER = 'W'
}	t_tile_type;

typedef struct s_tex_mgnt
{
	char		*cmp;
	t_textures	textures;
}	t_tex_mgnt;

typedef struct s_ttype_mgnt
{
	t_tile_type	tile_type;
}	t_ttype_mgnt;

typedef struct s_vec2
{
	size_t	x;
	size_t	y;
}	t_vec2;

typedef struct s_map
{
	char	**tab_map;
	size_t	height;
	size_t	max_width;
	size_t	current_width;
	size_t	nb_player;
	char	p_orient;
	t_vec2	p_pos;
}	t_map;

typedef struct s_ctx
{
	char	*textures[NB_ALL_TEXTURES];
	t_map	*map;
	size_t	n_textures;
}	t_ctx;

//parsing.c
int				parsing(char *file, t_ctx *ctx);

//parse_textures.c
int		parse_path(char **textures);
int		parse_textures(char *line_read, t_ctx *ctx);

//parse_color.c
int		parse_color(char **color);

//parse_map.c
int		parse_map(t_map *map);
int		check_line_map(char *line_read, t_map *map);

//valid_map.c
int		valid_lcolumn_border(char **tab_map, size_t height);
int		valid_rcolumn_border(char **tab_map, size_t height);
int		valid_border_line(char **tab_map, size_t max_height);

#endif
