/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:57:08 by ldepenne          #+#    #+#             */
/*   Updated: 2026/06/26 23:27:24 by ldepenne         ###   ########.fr       */
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

# ifndef EXT_FILE
#  define EXT_FILE ".cub"
# endif

typedef struct s_texures
{
	char		*NO_texture;
	char		*SO_texture;
	char		*WE_texture;
	char		*EA_texture;
	char		*F_color;
	char		*C_color;
}				t_textures;

typedef struct s_map
{
	char		**tab_map;
	size_t		height;
	size_t		width;
	char		start_pos;
}				t_map;

typedef struct s_ctx
{
	t_textures	textures;
	t_map		map;
}				t_ctx;

// parsing.c
int				parsing(char *file, t_ctx *ctx);

// parse_textures.c
void			extract_textures(char *file, t_textures *textures);

// utils.c
void			print_error(char *err_msg);
void			free_ctx(t_ctx *ctx);

#endif
