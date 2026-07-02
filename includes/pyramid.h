/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:57:08 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/02 12:01:26 by ldepenne         ###   ########.fr       */
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
# include <stdbool.h>

# define EXT_FILE ".cub"
# define NB_COLOR 2
# define NB_PATH_TEXTURES 4
# define NB_ALL_TEXTURES NB_COLOR + NB_PATH_TEXTURES

typedef enum e_tile_type
{
	FLOOR,
	WALL,
	EMPTY,
	PLAYER
}	t_tile_type;

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
	t_tile_type	**tab_map;
	size_t		height;
	size_t		width;
	char		p_orientation;
	bool		n_player;
}	t_map;

typedef struct s_ctx
{
	char	*textures[NB_ALL_TEXTURES];
	t_map	*map;
	int		nb_textures;
	bool	start_check_map;
}	t_ctx;

//parsing.c
int		parsing(char *file, t_ctx *ctx);

//parse_textures.c
int		parse_color(char **color);
int		parse_path(char **textures);
int		parse_textures(char *line_read, t_ctx *ctx);

//parse_map.c
int		parse_map(char *line_read, t_map *map);

//utils.c
void	print_error(char *err_msg);
void	free_ctx(t_ctx *ctx);

#endif